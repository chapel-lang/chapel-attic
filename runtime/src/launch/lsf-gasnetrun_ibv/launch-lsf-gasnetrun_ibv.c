#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include "chpllaunch.h"
#include "chpl-mem.h"
#include "error.h"

// from ../gasnetrun_ibv/launch-gasnetrun_ibv.c:
#define WRAP_TO_STR(x) TO_STR(x)
#define TO_STR(x) #x

//
// we will build this command:
//   bsub ... LAUNCH_PATH/gasnetrun_ibv ... REAL_BINNAME ...
//
// bsub options used:
//  -R span[ptile=1]   seems to request just 1 process per node
//  -n NN              request NN processors (i.e. nodes?)
//  -Ip                requests an interactive session with a pseudo-terminal
//
// bsub other options:
//  -K  wait for job completion - could use instead of -Ip,
//      but stdin/out/err are disconnected (use -i/-o/-e to direct to files)
//  there does not seem to be a "quiet" option
//

static char _nlbuf[16];
static char** chpl_launch_create_argv(int argc, char* argv[],
                                      int32_t numLocales) {
  int len = strlen(WRAP_TO_STR(LAUNCH_PATH)) + strlen("gasnetrun_ibv") + 1;
  char *cmd = chpl_mem_allocMany(len, sizeof(char), CHPL_RT_MD_COMMAND_BUFFER, -1, "");
  sprintf(cmd, "%sgasnetrun_ibv", WRAP_TO_STR(LAUNCH_PATH));

  const int largc = 9;
  char *largv[largc];

  largv[0] = "bsub";
  largv[1] = "-Ip";
  largv[2] = "-R";
  largv[3] = "span[ptile=1]";
  largv[4] = "-n";
  sprintf(_nlbuf, "%d", numLocales);
  largv[5] = _nlbuf;
  largv[6] = cmd;
  largv[7] = "-n";
  largv[8] = _nlbuf;
  
  return chpl_bundle_exec_args(argc, argv, largc, largv);
}


int chpl_launch(int argc, char* argv[], int32_t numLocales) {
  return chpl_launch_using_exec("bsub",
                                chpl_launch_create_argv(argc, argv, numLocales),
                                argv[0]);
}


int chpl_launch_handle_arg(int argc, char* argv[], int argNum,
                           int32_t lineno, chpl_string filename) {
  return 0;
}


void chpl_launch_print_help(void) {
}
