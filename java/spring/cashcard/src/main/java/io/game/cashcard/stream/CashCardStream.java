package io.game.cashcard.stream;

import io.game.cashcard.domain.Transaction;
import io.game.cashcard.service.DataSourceService;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

import java.util.function.Supplier;

@Configuration
public class CashCardStream {

    @Bean
    public Supplier<Transaction> approvalRequests(DataSourceService dataSource) {
        return dataSource::getData;
    }
}
