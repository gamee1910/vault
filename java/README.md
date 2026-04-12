# Java Module

This directory contains Java projects and modules, including:

## Directory Structure

### `/algo`
Contains basic algorithm implementations in Java:
- **`binarySearch/`** - Binary search algorithm implementation
- **`stack/`** - Stack data structure implementation and related applications (such as mathematical expression evaluation)

### `/infra`
Contains infrastructure configuration:
- **`infra.yml`** - Docker Compose configuration file for starting services like PostgreSQL, Redis, etc.

### `/spring`
Contains various Spring Boot projects:

#### `spring-jdbc/`
Spring Boot application demonstrating how to use JDBC for database access. Includes basic examples of connection management and SQL query execution.

#### `spring-jooq/`
Spring Boot application providing a small REST API CRUD for `goods` using:
- **jOOQ** - SQL Builder library for writing type-safe SQL queries
- **Liquibase** - Schema migration management tool
- **PostgreSQL** - Database

See [spring-jooq README](./spring/spring-jooq/README.md) for more details.

## Key Technologies

- **Java 17+**
- **Spring Boot 4.x**
- **jOOQ** - Typed SQL builder
- **Liquibase** - Database versioning
- **PostgreSQL** - Database
- **Maven** - Build tool

## Requirements

- JDK 17+
- Maven (or use Maven Wrapper `./mvnw`)
- Docker + Docker Compose (for projects using databases)

## Getting Started

Each Spring Boot project has its own guide. For example, to run `spring-jooq`:

```bash
cd spring/spring-jooq
./mvnw spring-boot:run
```

## Purpose

This directory stores exercises, practical examples, and sample projects for:
- Basic algorithms
- Data structures
- Spring Boot applications
- Database integration


