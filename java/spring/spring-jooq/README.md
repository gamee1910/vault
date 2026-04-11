# spring-jooq

Spring Boot module that exposes a small CRUD API for `goods` using jOOQ for SQL access, Liquibase for schema migrations, and PostgreSQL as the database.

## What this module includes

- Spring Boot application entry point: `src/expression/java/com/vault/jooq/Application.java`
- REST controller: `src/expression/java/com/vault/jooq/controller/GoodsController.java`
- Service with jOOQ queries: `src/expression/java/com/vault/jooq/service/GoodsService.java`
- DTO record: `src/expression/java/com/vault/jooq/dto/GoodsDTO.java`
- Liquibase changelog: `src/expression/resources/db/changelog.yml`
- Initial schema migration: `src/expression/resources/db/migrations/ddl/init_schema.yml`

## Tech stack

- Java 17
- Spring Boot 4
- jOOQ
- Liquibase
- PostgreSQL
- Maven Wrapper (`./mvnw`)

## Data model

Table: `GOODS`

Columns:
- `id` (`UUID`, primary key, not null)
- `name` (`VARCHAR(255)`, not null)
- `price` (`numeric`)
- `total_count` (`integer`)
- `sold_count` (`integer`)
- `deleted` (`boolean`)

Defined in: `src/expression/resources/db/migrations/ddl/init_schema.yml`

## Prerequisites

- JDK 17+
- Docker + Docker Compose (or a local PostgreSQL instance)

## Configuration

Application config is in `src/expression/resources/application.yml`:

- `spring.datasource.url=jdbc:postgresql://localhost:5432/goods_db`
- `spring.datasource.username=postgres`
- `spring.datasource.password=postgres`
- `spring.liquibase.change-log=classpath:db/changelog.yml`

By default, the module expects a PostgreSQL database named `goods_db` on `localhost:5432`.

## Start PostgreSQL

From repository root (`/home/game/projects/java/vault`):

```zsh
docker compose -f infra/infra.yml up -d postgres
```

Create the database if needed:

```zsh
docker exec -it postgres psql -U postgres -c "CREATE DATABASE goods_db;"
```

## Run the application

From `spring/spring-jooq`:

```zsh
./mvnw spring-boot:run
```

Liquibase migrations are applied automatically on startup.

## API

Base path: `/goods`

- `POST /goods/create` - create item
- `GET /goods/{id}` - get by id
- `PUT /goods/update` - update item
- `DELETE /goods/delete/{id}` - soft delete (`deleted=true`)
- `GET /goods` - list all items

`GoodsDTO` JSON shape:

```json
{
  "id": "uuid",
  "name": "string",
  "price": 10.50,
  "totalCount": 100,
  "soldCount": 5,
  "deleted": false
}
```

## Build and test

From `spring/spring-jooq`:

```zsh
./mvnw test
./mvnw package
```

Current test coverage includes a Spring context load test in `src/test/java/com/vault/jooq/SpringJooqApplicationTests.java`.

## jOOQ code generation

The module has `jooq-codegen-maven` configured in `pom.xml` for the local PostgreSQL connection.

Run code generation manually from `spring/spring-jooq`:

```zsh
./mvnw jooq-codegen:generate
```

Generated sources are produced under `target/generated-sources/jooq`.

## OpenAPI / Swagger UI

The module includes `springdoc-openapi-starter-webmvc-ui`.

When the app is running, Swagger UI is typically available at:

- `http://localhost:8080/swagger-ui/index.html`

## Troubleshooting

- If startup fails with database connection errors, verify PostgreSQL is running and `goods_db` exists.
- If schema errors appear, check Liquibase files in `src/expression/resources/db/changelog.yml` and `src/expression/resources/db/migrations/ddl`.
- If jOOQ classes are missing, run `./mvnw jooq-codegen:generate` and rebuild.

