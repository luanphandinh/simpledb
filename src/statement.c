#include "types.c"
#include <stdio.h>
#include <string.h>

PrepareResult prepare_insert_statement(InputBuffer *input_buffer,
                                       Statement *statement) {
  statement->type = STATEMENT_INSERT;
  int arg_assigned = sscanf(
      input_buffer->buffer, "insert %d %s %s", &(statement->row_to_insert.id),
      statement->row_to_insert.username, statement->row_to_insert.email);
  if (arg_assigned < 3) {
    return PREPARE_SYNTAX_ERROR;
  }
  return PREPARE_SUCCESS;
}

PrepareResult prepare_select_statement(InputBuffer *input_buffer,
                                       Statement *statement) {
  statement->type = STATEMENT_SELECT;
  return PREPARE_SUCCESS;
}

PrepareResult prepare_statement(InputBuffer *input_buffer,
                                Statement *statement) {
  if (strncmp(input_buffer->buffer, "insert", 6) == 0) {
    return prepare_insert_statement(input_buffer, statement);
  }

  if (strncmp(input_buffer->buffer, "select", 6) == 0) {
    return prepare_select_statement(input_buffer, statement);
  }

  return PREPARE_UNREGONIZED_STATEMENT;
}

ExecuteResult execute_insert_statement(Statement *statement, Table *table) {
  if (table->num_rows > TABLE_MAX_ROWS) {
    return EXECUTE_TABLE_FULL;
  }

  void* page = row_slot(table, table->num_rows);
  serialize_row(&(statement->row_to_insert), page);
  table->num_rows++;

  return EXECUTE_SUCCESS;
}

ExecuteResult execute_select_statement(Statement *statement, Table* table) {
  Row row;
  for (uint32_t i = 0; i < table->num_rows; i++) {
    deserialize_row(row_slot(table, i), &row);
    print_row(&row);
  }
  return EXECUTE_SUCCESS;
}

ExecuteResult execute_statement(Statement *statement, Table* table) {
  switch (statement->type) {
  case (STATEMENT_INSERT):
    return execute_insert_statement(statement, table);
  case (STATEMENT_SELECT):
    return execute_select_statement(statement, table);
  }
}
