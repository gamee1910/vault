package io.game.cashcard.domain;

public record CashCard(
        Long id,
        String owner,
        Double amountRequestedForAuth
) {
}
