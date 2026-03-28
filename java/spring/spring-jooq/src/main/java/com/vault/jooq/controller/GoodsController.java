package com.vault.jooq.controller;

import com.vault.jooq.dto.GoodsDTO;
import com.vault.jooq.service.GoodsService;
import lombok.RequiredArgsConstructor;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import java.util.List;
import java.util.UUID;

@RestController
@RequiredArgsConstructor
@RequestMapping("/goods")
public class GoodsController {

    private final GoodsService goodsService;

    @PostMapping("/create")
    public ResponseEntity<GoodsDTO> create(@RequestBody GoodsDTO goods) {
        return ResponseEntity.status(HttpStatus.CREATED).body(goodsService.create(goods));
    }

    @GetMapping("/{id}")
    public ResponseEntity<GoodsDTO> getById(@PathVariable UUID id) {
        return ResponseEntity.status(HttpStatus.OK).body(goodsService.getById(id));
    }

    @PutMapping("/update")
    public ResponseEntity<GoodsDTO> update(@RequestBody GoodsDTO goods) {
        return ResponseEntity.status(HttpStatus.CREATED).body(goodsService.update(goods));
    }

    @DeleteMapping("/delete/{id}")
    public ResponseEntity<Void> delete(@PathVariable UUID id) {
        goodsService.delete(id);
        return ResponseEntity.noContent().build();
    }

    @GetMapping
    public ResponseEntity<List<GoodsDTO>> getAll() {
        return ResponseEntity.status(HttpStatus.OK).body(goodsService.getAll());
    }
}
