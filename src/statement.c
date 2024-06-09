#include "types.c"
#include <string.h>

PrepareResult prepare_insert_statement(InputBuffer *input_buffer, Statement *statement) {
  statement->type = STATEMENT_INSERT;
  return PREPARE_SUCCESS;
}

PrepareResult prepare_update_statement(InputBuffer *input_buffer, Statement *statement) {
  statement->type = STATEMENT_INSERT;
  return PREPARE_SUCCESS;
}

PrepareResult prepare_statement(InputBuffer *input_buffer,
                                Statement *statement) {
  if (strncmp(input_buffer->buffer, "insert", 6) == 0) {
    return prepare_insert_statement(input_buffer, statement);
  }

  if (strncmp(input_buffer->buffer, "update", 6) == 0) {
    return prepare_update_statement(input_buffer, statement);
  }

  return PREPARE_UNREGONIZED_STATEMENT;
}

void execute_statement(Statement *statement) {
  switch (statement->type) {
    case(STATEMENT_INSERT):
      printf("This is where we would do insert.\n");
      break;
    case(STATEMENT_UPDATE):
      printf("This is where we would do update.\n");
      break;
  }
}
