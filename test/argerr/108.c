/* 
TEST_HEADER
 id = $Id$
 summary = MAX+1 root mode for mps_root_create_table
 language = c
 link = testlib.o
OUTPUT_SPEC
 assert = true
 assertfile P= root.c
 assertcond = (mode & (RootModeCONSTANT | RootModePROTECTABLE | RootModePROTECTABLE_INNER)) == mode
END_HEADER
*/

#include "testlib.h"
#include "arg.h"

void *stackpointer;

static void test(void)
{
 mps_arena_t arena;
 mps_thr_t thread;
 mps_root_t root;
 mps_addr_t a[30];

 cdie(mps_arena_create(&arena, mps_arena_class_vm(), mmqaArenaSIZE), "create arena");

 cdie(mps_thread_reg(&thread, arena), "register thread");

 cdie(mps_root_create_table(&root, arena,
        mps_rank_ambig(), 8, a, sizeof a),
      "root create");

}

int main(void)
{
 void *m;
 stackpointer=&m; /* hack to get stack pointer */

 easy_tramp(test);
 return 0;
}
