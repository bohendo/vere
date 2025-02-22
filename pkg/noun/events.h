/// @file

#ifndef U3_EVENTS_H
#define U3_EVENTS_H

#include "c3.h"
#include "allocate.h"
#include "version.h"

  /** Data structures.
  **/
    /* u3e_line: control line.
    */
      typedef struct _u3e_line {
        c3_w pag_w;
        c3_w mug_w;
      } u3e_line;

    /* u3e_control: memory change, control file.
    */
      typedef struct _u3e_control {
        u3e_version ver_w;                  //  version number
        c3_w        nor_w;                  //  new page count north
        c3_w        sou_w;                  //  new page count south
        c3_w        pgs_w;                  //  number of changed pages
        u3e_line    mem_u[0];               //  per page
      } u3e_control;

    /* u3_cs_patch: memory change, top level.
    */
      typedef struct _u3_cs_patch {
        c3_i         ctl_i;
        c3_i         mem_i;
        u3e_control* con_u;
      } u3_ce_patch;

    /* u3e_image: memory segment, open file.
    */
      typedef struct _u3e_image {
        c3_c* nam_c;                        //  segment name
        c3_i  fid_i;                        //  open file, or 0
        c3_w  pgs_w;                        //  length in pages
      } u3e_image;

    /* u3e_pool: entire memory system.
    */
      typedef struct _u3e_pool {
        c3_c*     dir_c;                     //  path to
        c3_w      dit_w[u3a_pages >> 5];     //  touched since last save
        c3_w      pag_w;                     //  number of pages (<= u3a_pages)
        u3e_image nor_u;                     //  north segment
        u3e_image sou_u;                     //  south segment
      } u3e_pool;


  /** Globals.
  **/
      /// Snapshotting system.
      extern u3e_pool u3e_Pool;
#     define u3P u3e_Pool

  /** Constants.
  **/

  /** Functions.
  **/
    /* u3e_backup(): copy the snapshot from chk to bhk. 
    */
      c3_o 
      u3e_backup(c3_o ovw_o);

    /* u3e_fault(): handle a memory event with libsigsegv protocol.
    */
      c3_i
      u3e_fault(void* adr_v, c3_i ser_i);

    /* u3e_save():
    */
      void
      u3e_save(void);

    /* u3e_live(): start the persistence system.  Return c3y if no image.
    */
      c3_o
      u3e_live(c3_o nuu_o, c3_c* dir_c);

    /* u3e_yolo(): disable dirty page tracking, read/write whole loom.
    */
      c3_o
      u3e_yolo(void);

    /* u3e_foul(): dirty all the pages of the loom.
    */
      void
      u3e_foul(void);

    /* u3e_init(): initialize guard page tracking.
    */
      void
      u3e_init(void);

    /* u3e_ward(): reposition guard page if needed.
    */
      void
      u3e_ward(u3_post low_p, u3_post hig_p);

#endif /* ifndef U3_EVENTS_H */
