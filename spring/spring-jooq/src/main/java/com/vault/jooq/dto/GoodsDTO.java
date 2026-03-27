package com.vault.jooq.dto;

import java.math.BigDecimal;
import java.util.UUID;

public record GoodsDTO(UUID id, String name, BigDecimal price, Integer totalCount, Integer soldCount, boolean deleted) {
}
