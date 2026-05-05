package io.game.cashcard.stream;

import io.game.cashcard.domain.CashCard;
import io.game.cashcard.domain.Transaction;
import io.game.cashcard.service.DataSourceService;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.cloud.stream.binder.test.OutputDestination;
import org.springframework.cloud.stream.binder.test.TestChannelBinderConfiguration;
import org.springframework.context.annotation.Import;
import org.springframework.messaging.Message;
import org.springframework.test.context.bean.override.mockito.MockitoBean;

import java.io.IOException;

import static org.assertj.core.api.Assertions.assertThat;
import static org.mockito.BDDMockito.given;

@SpringBootTest
@Import(TestChannelBinderConfiguration.class)
class CashcardApplicationTests {

    @MockitoBean
    private DataSourceService dataSourceService;

    @Test
    void basicCashCardSupplier1(@Autowired OutputDestination outputDestination) {
        Transaction testTransaction = new Transaction(1L, new CashCard(123L, "GAME", 1.00));
        given(dataSourceService.getData()).willReturn(testTransaction);

        Message<byte[]> result = outputDestination.receive(5000, "approvalRequests-out-0");
        assertThat(result).isNotNull();
    }
}
