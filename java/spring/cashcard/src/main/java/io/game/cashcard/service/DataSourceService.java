package io.game.cashcard.service;

import io.game.cashcard.domain.CashCard;
import io.game.cashcard.domain.Transaction;
import org.springframework.stereotype.Service;

import java.util.Random;

//Fake data class generator
@Service
public class DataSourceService {

    public Transaction getData() {
        CashCard cashCard = new CashCard(
                new Random().nextLong(),
                "Game",
                new Random().nextDouble()
        );
        return new Transaction(new Random().nextLong(), cashCard);
    }
}
