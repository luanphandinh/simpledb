#include <string.h>
#include "types.c"

PrepareResult prepare_statement(InputBuffer *input_buffer,
                                Statement *statement) {
  if (strncmp(input_buffer->buffer, "insert", 6) == 0) {
    statement->type = STATEMENT_INSERT;
    return PREPARE_SUCCESS;
  }

  if (strncmp(input_buffer->buffer, "update", 6) == 0) {
    statement->type = STATEMENT_UPDATE;
    return PREPARE_SUCCESS;
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
