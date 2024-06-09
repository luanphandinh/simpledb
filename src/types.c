#include <stdint.h>
#include <stdio.h>

typedef enum {
  STATEMENT_INSERT,
  STATEMENT_UPDATE,
} StatementType;

typedef enum {
  PREPARE_SUCCESS,
  PREPARE_UNREGONIZED_STATEMENT,
} PrepareResult;

typedef enum {
  META_COMMAND_SUCCESS,
  META_COMMAND_UNREGONIZED,
} MetaCommandResult;

typedef struct {
  char *buffer;
  size_t buffer_length;
  ssize_t input_length;
} InputBuffer;

#define COLUMN_USERNAME_SIZE 32
#define COLUMN_EMAIL_SIZE 255
typedef struct{
  uint32_t id;
  char username[COLUMN_USERNAME_SIZE];
  char email[COLUMN_EMAIL_SIZE];
} Row;

typedef struct {
  StatementType type;
  Row row_to_insert;
} Statement;

