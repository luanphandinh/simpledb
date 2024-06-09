#include <stdio.h>

typedef enum {
  STATEMENT_INSERT,
  STATEMENT_UPDATE,
} StatementType;

typedef enum {
  PREPARE_SUCCESS,
  PREPARE_UNREGONIZED_STATEMENT,
} PrepareResult;

typedef struct {
  StatementType type;
} Statement;

typedef enum {
  META_COMMAND_SUCCESS,
  META_COMMAND_UNREGONIZED,
} MetaCommandResult;

typedef struct {
  char *buffer;
  size_t buffer_length;
  ssize_t input_length;
} InputBuffer;
