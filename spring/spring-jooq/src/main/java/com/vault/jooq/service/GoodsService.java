package com.vault.jooq.service;

import com.vault.jooq.dto.GoodsDTO;
import lombok.AccessLevel;
import lombok.RequiredArgsConstructor;
import lombok.extern.slf4j.Slf4j;
import org.jooq.DSLContext;
import org.springframework.stereotype.Service;
import org.springframework.util.Assert;

import java.util.List;
import java.util.UUID;

import static org.jooq.generated.public_.tables.Goods.GOODS;

@Service
@RequiredArgsConstructor
@Slf4j(topic = "GoodsService", access = AccessLevel.PRIVATE)
public class GoodsService {

    private final DSLContext context;

    public List<GoodsDTO> getAll() {
        return context.select(
                        GOODS.ID,
                        GOODS.NAME,
                        GOODS.PRICE,
                        GOODS.SOLD_COUNT,
                        GOODS.TOTAL_COUNT,
                        GOODS.DELETED
                )
                .from(GOODS)
                .fetch(record -> new GoodsDTO(
                        record.get(GOODS.ID),
                        record.get(GOODS.NAME),
                        record.get(GOODS.PRICE),
                        record.get(GOODS.SOLD_COUNT),
                        record.get(GOODS.TOTAL_COUNT),
                        record.get(GOODS.DELETED)
                ));
    }

    public GoodsDTO create(GoodsDTO request) {
        var id = UUID.randomUUID();
        var result = context.insertInto(GOODS)
                .values(id, request.name(), request.price(), request.totalCount(), request.soldCount(), request.deleted())
                .execute();
        log.info("Inserted with result: {}", result);
        return this.getById(id);
    }

    public void delete(UUID id) {
        context.update(GOODS)
                .set(GOODS.DELETED, true)
                .where(GOODS.ID.eq(id))
                .execute();
    }

    public GoodsDTO update(GoodsDTO goods) {
        var updated = context.update(GOODS)
                .set(GOODS.ID, goods.id())
                .set(GOODS.NAME, goods.name())
                .set(GOODS.PRICE, goods.price())
                .set(GOODS.SOLD_COUNT, goods.soldCount())
                .set(GOODS.TOTAL_COUNT, goods.totalCount())
                .set(GOODS.DELETED, goods.deleted())
                .execute();
        log.info("Successfully updated {} rows", updated);
        return this.getById(goods.id());
    }

    public GoodsDTO getById(UUID id) {
        final var fetchedRecord = context.select(
                        GOODS.ID, GOODS.NAME, GOODS.PRICE, GOODS.SOLD_COUNT, GOODS.TOTAL_COUNT, GOODS.DELETED
                ).from(GOODS).where(GOODS.ID.eq(id))
                .fetchOne();
        Assert.notNull(fetchedRecord, "record with id = " + id + " is not exists");
        return new GoodsDTO(fetchedRecord.get(GOODS.ID),
                fetchedRecord.get(GOODS.NAME),
                fetchedRecord.get(GOODS.PRICE),
                fetchedRecord.get(GOODS.SOLD_COUNT),
                fetchedRecord.get(GOODS.TOTAL_COUNT),
                fetchedRecord.get(GOODS.DELETED)
        );
    }
}
