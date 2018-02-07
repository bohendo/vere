/* g/n.c
**
*/
#include "all.h"

static u3_noun _n_nock_on(u3_noun bus, u3_noun fol);

      /* u3_term_io_hija(): hijack console for cooked print.
      */
        FILE*
        u3_term_io_hija(void);

      /* u3_term_io_loja(): release console from cooked print.
      */
        void
        u3_term_io_loja(int x);

      /* uL, uH: wrap hijack/lojack around fprintf.
      **
      **  uL(fprintf(uH, ...));
      */
#       define uH    u3_term_io_hija()
#       define uL(x) u3_term_io_loja(x)


/* _n_hint(): process hint.
*/
static u3_noun
_n_hint(u3_noun zep, 
        u3_noun hod,
        u3_noun bus,
        u3_noun nex)
{
  switch ( zep ) {
    default: {
      // u3m_p("weird zep", zep);
      u3a_lose(zep);
      u3a_lose(hod);

      return _n_nock_on(bus, nex);
    }

    case c3__hunk:
    case c3__lose:
    case c3__mean:
    case c3__spot: {
      u3_noun tac = u3nc(zep, hod);
      u3_noun pro;

      u3t_push(tac);
#if 0
      {
        static int low_i;

        if ( !low_i ) {
          low_i = 1;
          if ( 0 == (u3R->pro.nox_d % 65536ULL) ) {
            if ( c3__spot == zep ) {
              uL(fprintf(uH, "spot %d/%d : %d/%d\r\n",
                             u3h(u3h(u3t(hod))),
                             u3t(u3h(u3t(hod))),
                             u3h(u3t(u3t(hod))),
                             u3t(u3t(u3t(hod)))));
            }
          }
          low_i = 0;
        }
      }
#endif
      pro = _n_nock_on(bus, nex);
      u3t_drop();

      return pro;
    }

    case c3__live: {
      if ( c3y == u3ud(hod) ) {
        u3t_off(noc_o);
        u3t_heck(hod);
        u3t_on(noc_o);
      } else {
        u3z(hod);
      }
      return _n_nock_on(bus, nex);
    }

    case c3__slog: {
      if ( !(u3C.wag_w & u3o_quiet) ) {
        u3t_off(noc_o);
        u3t_slog(hod);
        u3t_on(noc_o);
      }
      return _n_nock_on(bus, nex);
    }

    case c3__germ: {
      u3_noun pro = _n_nock_on(bus, nex);

      if ( c3y == u3r_sing(pro, hod) ) {
        u3z(pro); return hod;
      } else {
        u3z(hod); return pro;
      }
    }

    case c3__fast: {
      u3_noun pro = _n_nock_on(bus, nex);

      u3t_off(noc_o);
      u3j_mine(hod, u3k(pro));
      u3t_on(noc_o);

      return pro;
    }

    case c3__memo: {
      u3z(hod);
#if 0
      return _n_nock_on(bus, nex);
#else
      {
        u3_noun pro = u3z_find_2(144 + c3__nock, bus, nex);

        if ( pro != u3_none ) {
          u3z(bus); u3z(nex);
          return pro;
        }
        pro = _n_nock_on(u3k(bus), u3k(nex));

        if ( &(u3H->rod_u) != u3R ) {
          u3z_save_2(144 + c3__nock, bus, nex, pro);
        }

        u3z(bus); u3z(nex);

        return pro;
      }
#endif
    }

    case c3__sole: {
      u3z(hod);
      {
        u3_noun pro = _n_nock_on(bus, nex);

        // return u3z_uniq(pro);
        return pro;
      }
    }
  }
}

/* _n_mush_in(): see _n_mush().
*/
static u3_noun
_n_mush_in(u3_noun val)
{
  if ( c3n == u3du(val) ) {
    return u3_nul;
  }
  else {
    u3_noun h_val = u3h(val);
    u3_noun ite;

    if ( c3n == u3ud(h_val) ) {
      ite = u3nc(c3__leaf, u3_nul);
    } else {
      ite = u3nc(c3__leaf, u3qe_trip(h_val));
    }
    return u3nc(ite, _n_mush_in(u3t(val)));
  }
}

/* _n_mush(): tank from failed path request.
*/
static u3_noun 
_n_mush(u3_noun val)
{
  u3_noun pro;

  pro = u3nt(c3__rose,
             u3nt(u3nc('/', u3_nul), u3nc('/', u3_nul), u3_nul),
             _n_mush_in(val));
  u3z(val);
  return pro;
}

/* _n_nock_on(): produce .*(bus fol).  Do not virtualize.
*/
static u3_noun
_n_nock_on(u3_noun bus, u3_noun fol)
{
  u3_noun hib, gal;

  while ( 1 ) {
    hib = u3h(fol);
    gal = u3t(fol);

#ifdef U3_CPU_DEBUG
    u3R->pro.nox_d += 1;
#endif

    if ( c3y == u3r_du(hib) ) {
      u3_noun poz, riv;

      poz = _n_nock_on(u3k(bus), u3k(hib));
      riv = _n_nock_on(bus, u3k(gal));

      u3a_lose(fol);
      return u3i_cell(poz, riv);
    }
    else switch ( hib ) {
      default: return u3m_bail(c3__exit);

      case 0: {
        if ( c3n == u3r_ud(gal) ) {
          return u3m_bail(c3__exit);
        }
        else {
          u3_noun pro = u3k(u3at(gal, bus));

          u3a_lose(bus); u3a_lose(fol);
          return pro;
        }
      }
      c3_assert(!"not reached");

      case 1: {
        u3_noun pro = u3k(gal);

        u3a_lose(bus); u3a_lose(fol);
        return pro;
      }
      c3_assert(!"not reached");

      case 2: {
        u3_noun nex = _n_nock_on(u3k(bus), u3k(u3t(gal)));
        u3_noun seb = _n_nock_on(bus, u3k(u3h(gal)));

        u3a_lose(fol);
        bus = seb;
        fol = nex;
        continue;
      }
      c3_assert(!"not reached");

      case 3: {
        u3_noun gof, pro;

        gof = _n_nock_on(bus, u3k(gal));
        pro = u3r_du(gof);

        u3a_lose(gof); u3a_lose(fol);
        return pro;
      }
      c3_assert(!"not reached");

      case 4: {
        u3_noun gof, pro;

        gof = _n_nock_on(bus, u3k(gal));
        pro = u3i_vint(gof);

        u3a_lose(fol);
        return pro;
      }
      c3_assert(!"not reached");

      case 5: {
        u3_noun wim = _n_nock_on(bus, u3k(gal));
        u3_noun pro = u3r_sing(u3h(wim), u3t(wim));

        u3a_lose(wim); u3a_lose(fol);
        return pro;
      }
      c3_assert(!"not reached");

      case 6: {
        u3_noun b_gal, c_gal, d_gal;

        u3x_trel(gal, &b_gal, &c_gal, &d_gal);
        {
          u3_noun tys = _n_nock_on(u3k(bus), u3k(b_gal));
          u3_noun nex;

          if ( 0 == tys ) {
            nex = u3k(c_gal);
          } else if ( 1 == tys ) {
            nex = u3k(d_gal);
          } else return u3m_bail(c3__exit);

          u3a_lose(fol);
          fol = nex;
          continue;
        }
      }
      c3_assert(!"not reached");

      case 7: {
        u3_noun b_gal, c_gal;

        u3x_cell(gal, &b_gal, &c_gal);
        {
          u3_noun bod = _n_nock_on(bus, u3k(b_gal));
          u3_noun nex = u3k(c_gal);

          u3a_lose(fol);
          bus = bod;
          fol = nex;
          continue;
        }
      }
      c3_assert(!"not reached");

      case 8: {
        u3_noun b_gal, c_gal;

        u3x_cell(gal, &b_gal, &c_gal);
        {
          u3_noun heb = _n_nock_on(u3k(bus), u3k(b_gal));
          u3_noun bod = u3nc(heb, bus);
          u3_noun nex = u3k(c_gal);

          u3a_lose(fol);
          bus = bod;
          fol = nex;
          continue;
        }
      }
      c3_assert(!"not reached");

      case 9: {
        u3_noun b_gal, c_gal;

        u3x_cell(gal, &b_gal, &c_gal);
        {
          u3_noun seb = _n_nock_on(bus, u3k(c_gal));
          u3_noun pro;
         
          u3t_off(noc_o);
          pro = u3j_kick(seb, b_gal);
          u3t_on(noc_o);

          if ( u3_none != pro ) {
            u3a_lose(fol);
            return pro;
          }
          else {
            if ( c3n == u3r_ud(b_gal) ) {
              return u3m_bail(c3__exit);
            }
            else {
              u3_noun nex = u3k(u3at(b_gal, seb));

              u3a_lose(fol);
              bus = seb;
              fol = nex;
              continue;
            }
          }
        }
      }
      c3_assert(!"not reached");

      case 10: {
        u3_noun p_gal, q_gal;

        u3x_cell(gal, &p_gal, &q_gal);
        {
          u3_noun zep, hod, nex;

          if ( c3y == u3r_du(p_gal) ) {
            u3_noun b_gal = u3h(p_gal);
            u3_noun c_gal = u3t(p_gal);
            u3_noun d_gal = q_gal;

            zep = u3k(b_gal);
            hod = _n_nock_on(u3k(bus), u3k(c_gal));
            nex = u3k(d_gal);
          }
          else {
            u3_noun b_gal = p_gal;
            u3_noun c_gal = q_gal;

            zep = u3k(b_gal);
            hod = u3_nul;
            nex = u3k(c_gal);
          }

          u3a_lose(fol);
          return _n_hint(zep, hod, bus, nex);
        }
      }

      case 11: {
        u3_noun ref = _n_nock_on(u3k(bus), u3k(u3h(gal)));
        u3_noun gof = _n_nock_on(bus, u3k(u3t(gal)));
        u3_noun val;

        u3t_off(noc_o);
        val = u3m_soft_esc(ref, u3k(gof));
        u3t_on(noc_o);

        if ( !_(u3du(val)) ) {
          u3m_bail(u3nt(1, gof, 0));
        } 
        if ( !_(u3du(u3t(val))) ) {
          //
          //  replace with proper error stack push
          //
          u3t_push(u3nc(c3__hunk, _n_mush(gof)));
          return u3m_bail(c3__exit);
        }
        else {
          u3_noun pro;

          u3z(gof);
          u3z(fol);
          pro = u3k(u3t(u3t(val)));
          u3z(val);

          return pro;
        }
      }  
      c3_assert(!"not reached");
    }
  }
}

/* u3n_nock_on(): produce .*(bus fol).  Do not virtualize.
*/
u3_noun
u3n_nock_on(u3_noun bus, u3_noun fol)
{
  u3_noun pro;

  u3t_on(noc_o);
  pro = _n_nock_on(bus, fol);
  u3t_off(noc_o);

  return pro;
}

/* u3n_kick_on(): fire `gat` without changing the sample.
*/
u3_noun
u3n_kick_on(u3_noun gat)
{
  return u3j_kink(gat, 2);
}

c3_w exc_w;

/* u3n_slam_on(): produce (gat sam).
*/
u3_noun
u3n_slam_on(u3_noun gat, u3_noun sam)
{
  u3_noun cor = u3nc(u3k(u3h(gat)), u3nc(sam, u3k(u3t(u3t(gat)))));

#if 0
  if ( &u3H->rod_u == u3R ) {
    if ( exc_w == 1 ) {
      c3_assert(0);
    } 
    exc_w++;
  }
#endif
  u3z(gat);
  return u3n_kick_on(cor);
}

/* u3n_nock_et(): produce .*(bus fol), as ++toon, in namespace.
*/
u3_noun
u3n_nock_et(u3_noun gul, u3_noun bus, u3_noun fol)
{
  return u3m_soft_run(gul, u3n_nock_on, bus, fol);
}

/* u3n_slam_et(): produce (gat sam), as ++toon, in namespace.
*/
u3_noun
u3n_slam_et(u3_noun gul, u3_noun gat, u3_noun sam)
{
  return u3m_soft_run(gul, u3n_slam_on, gat, sam);
}

/* u3n_nock_an(): as slam_in(), but with empty fly.
*/
u3_noun
u3n_nock_an(u3_noun bus, u3_noun fol)
{
  u3_noun gul = u3nt(u3nt(1, 0, 0), 0, 0);  //  |=(a/{* *} ~)

  return u3n_nock_et(gul, bus, fol);
}

/* These must match the order in the section marked OPCODE TABLE */
#define HALT 0  // stop executing, leaving the product on the top of stack
#define COPY 1  // copy TOS, keep, and push it
#define TOSS 2  // throw away and lose TOS
#define SWAP 3  // exchange TOS with item underneat
#define SWAT 4  // toss item under TOS (under)
#define SKIP 5  // skip N (c3_s) instructions
#define SKIN 6  // pop loob, skip N if it is no, bail if not yes
#define SBIP 7  // skip with byte argument
#define SBIN 8  // skin with byte argument
#define CONS 9  // makes a cell of [under, TOS]
#define SNOC 10 // makes a cell of [TOS, under]
#define HEAD 11 // replaces TOS with its head (old TOS lost)
#define TAIL 12 // as HEAD, but for the tail
#define FRAG 13 // as HEAD/TAIL but with arbitrary noun axis
#define FRAS 14 // frag with short
#define FRAB 15 // frag with byte axis
#define QUOT 16 // toss TOS, push literal noun argument
#define QUIP 17 // as QUOT, but without the toss
#define NOCK 18 // *(under, TOS)
#define NOCT 19 // as NOCK, but in tail position
#define DEEP 20 // pop TOS and push isCell loob
#define PEEP 21 // as DEEP, but doesn't pop
#define BUMP 22 // increment TOS
#define SAME 23 // pop two items and push equality loob
#define KICK 24 // pull noun axis from TOS
#define KICS 25 // kick with short axis
#define KICB 26 // kick with byte axis
#define TICK 27 // KICK, but in tail position
#define TICS 28 // tick with short axis
#define TICB 29 // tick with byte axis
#define WISH 30 // ref is under, gof is TOS, u3m_soft_esc
#define FAST 31 // u3j_mine TOS
#define CUSH 32 // u3t_push TOS
#define DROP 33 // u3t_drop
#define PUMO 34 // saves memo from tos->[pro key]
#define GEMO 35 // pushes (unit pro) of u3z_save with key=TOS
#define HECK 36 // u3t_heck TOS
#define SLOG 37 // u3t_slog TOS
#define BAIL 37 // bail %exit

/* _n_apen(): emit the instructions contained in src to dst
 */
static inline void
_n_apen(u3_noun* dst, u3_noun src)
{
  *dst = u3qb_weld(src, *dst);
}

/* _n_emit(): emit a single instruction to ops, returning
 *            the size (in bytes) required to store that
 *            opcode.
 */
static inline c3_y
_n_emit(u3_noun *ops, u3_noun op)
{
  *ops = u3nc(op, *ops);
  if ( c3n == u3du(op) ) {
    return sizeof(c3_y);
  }
  else switch ( u3h(op) ) {
    case SBIP:
    case SBIN:
    case KICB:
    case TICB:
    case FRAB:
      return sizeof(c3_y) + sizeof(c3_y);

    case KICS:
    case TICS:
    case FRAS:
    case SKIP:
    case SKIN: 
      return sizeof(c3_y) + sizeof(c3_s);

    case FRAG:
    case QUOT:
    case QUIP:
    case TICK:
    case KICK:
      return sizeof(c3_y) + sizeof(u3_noun);
    default:
      c3_assert(0);
  }
}

static c3_s _n_comp(u3_noun*, c3_o*, u3_noun, c3_o);

static u3_noun
_n_skip(c3_s len_s)
{
  return u3nc((len_s < 0xFF ? SBIP : SKIP), len_s);
}

static u3_noun
_n_skin(c3_s len_s)
{
  return u3nc((len_s < 0xFF ? SBIN : SKIN), len_s);
}

/* _n_one(): emit non-tail fol's ops with a leading copy if not constant */
static c3_s
_n_one(u3_noun* ops, c3_o* tos_o, u3_noun fol)
{
  c3_assert(c3y == u3du(fol));
  c3_s tot_s = 0;
  u3_noun bok = u3_nul;

  tot_s += _n_comp(&bok, tos_o, fol, c3n);
  if ( c3n == *tos_o ) {
    tot_s += _n_emit(ops, COPY);
  }
  _n_apen(ops, bok);

  return tot_s;
}

/* _n_two(): _n_comp() helper for computing two products
 *           from a single subject
 */
static c3_s
_n_two(u3_noun* ops, c3_o* lev_o, u3_noun one, u3_noun two, c3_o cop_o)
{
  u3_noun one_bok = u3_nul,
          two_bok = u3_nul;

  c3_s tot_s = 0;
  c3_o one_o, two_o;

  tot_s += _n_comp(&one_bok, &one_o, one, cop_o, c3n);
  tot_s += _n_comp(&two_bok, &two_o, two, cop_o, c3n);

  if ( c3y == one_o ) {
    if ( c3y == two_o ) {
      _n_apen(ops, one_bok);
      _n_apen(ops, two_bok);
      *lev_o = c3y;
    }
    else {
      _n_apen(ops, one_bok);
      tot_s += _n_emit(ops, SWAP);
      _n_apen(ops, two_bok);
      *lev_o = c3n;
    }
  }
  else {
    if ( c3y == two_o ) {
      _n_apen(ops, one_bok);
      _n_apen(ops, two_bok);
      *lev_o = c3n;
    }
    else {
      tot_s += _n_emit(ops, COPY);
      _n_apen(ops, one_bok);
      tot_s += _n_emit(ops, SWAP);
      _n_apen(ops, two_bok);
      *lev_o = c3n;
    }
  }

  return tot_s;
}

/* _n_bint(): hint-processing helper for _n_comp.
 *            hif: hint-formula (first part of 10). RETAIN.
 *            nef: next-formula (second part of 10). RETAIN.
 */
static c3_s
_n_bint(u3_noun* ops, c3_o* tos_o, u3_noun hif, u3_noun nef, c3_o tel_o)
{
  *tos_o = c3n;
  // XX todo: hints don't currently participate in optimization because it's
  // complicated and i want to test it without them.
  if ( c3n == u3du(hif) ) {
    // no currently recognized static hints
    return _n_comp(ops, tos_o, nef, tel_o);
  }
  else {
    c3_s tot_s = 0;
    u3_noun zep, hod;
    u3x_cell(hif, &zep, &hod);

    switch ( zep ) {
      default:
        tot_s += _n_one(ops, tos_o, hod);
        tot_s += _n_emit(ops, TOSS);
        tot_s += _n_comp(ops, tos_o, nef, tel_o);
        break;

      case c3__hunk:
      case c3__lose:
      case c3__mean:
      case c3__spot: 
        tot_s += _n_one(ops, tos_o, hod);
        tot_s += _n_emit(ops, u3nc(QUIP, zep));
        tot_s += _n_emit(ops, SNOC);
        tot_s += _n_emit(ops, CUSH);
        tot_s += _n_comp(ops, tos_o, nef, c3n);
        tot_s += _n_emit(ops, DROP);
        break;

      case c3__live: {
        u3_noun yep = u3_nul,
                nop = u3_nul;
        c3_s    y_s = 0,
                n_s = 0;

        tot_s += _n_one(ops, tos_o, hod);
        tot_s += _n_emit(ops, PEEP);

        n_s += _n_emit(&nop, HECK);

        y_s += _n_emit(&yep, TOSS);
        y_s += _n_emit(&yep, _n_skip(n_s));

        tot_s += _n_emit(ops, _n_skin(y_s));
        _n_apen(ops, yep); tot_s += y_s;
        _n_apen(ops, nop); tot_s += n_s;

        tot_s += _n_comp(ops, tos_o, nef, tel_o);
        break;
      }

      case c3__slog: 
        tot_s += _n_one(ops, tos_o, hod);
        tot_s += _n_emit(ops, SLOG);
        tot_s += _n_comp(ops, tos_o, nef, tel_o);
        break;

      // germ and sole are unused...

      case c3__fast: 
        tot_s += _n_two(ops, tos_o, hod, nef);
        tot_s += _n_emit(ops, FAST);
        break;

      case c3__memo: {
        u3_noun nop = u3_nul,
                yep = u3_nul;

        c3_s y_s = 0,
             n_s = 0;                                // top->[bus]
        tot_s += _n_emit(ops, COPY);                 // [bus bus]
        tot_s += _n_one(ops, tos_o, hod);           // [clue bus bus]
        tot_s += _n_emit(ops, TOSS);                 // [bus bus]
        tot_s += _n_emit(ops, u3nc(QUIP, u3k(nef))); // [fol bus bus]
        tot_s += _n_emit(ops, SNOC);                 // [[bus fol] bus]
        tot_s += _n_emit(ops, GEMO);                 // [u key bus]
        tot_s += _n_emit(ops, PEEP);                 // [b u key bus]

        // NO branch, i.e. gemo gave us ~
        n_s += _n_emit(&nop, TOSS);                  // [key bus]
        n_s += _n_emit(&nop, SWAP);                  // [bus key]
        n_s += _n_comp(&nop, tos_o, nef, c3n);      // [pro key]
        n_s += _n_emit(&nop, PUMO);

        // YES branch, i.e. gemo gave us [0 pro]
        y_s += _n_emit(&yep, TAIL);                  // [pro key bus]
        y_s += _n_emit(&yep, SWAT);                  // [pro bus]
        y_s += _n_emit(&yep, _n_skip(n_s));

        tot_s += _n_emit(ops, _n_skin(y_s));
        _n_apen(ops, yep); tot_s += y_s;
        _n_apen(ops, nop); tot_s += n_s;

        // both branches leave an extra value under the top
        tot_s += _n_emit(ops, SWAT);
        break;
      }
    }
    return tot_s;
  }
}

/* _n_comp(): compile nock formula to reversed opcode list
 *            ops is a pointer to a list (to be emitted to)
 *            lev_o is written: c3y/n whether the operand is left on the stack
 *            fol is the nock formula to compile. RETAIN.
 *            cop_o indicates the subject/product stack position is a COPY
 *              if this is taken advantage of (lev_o), the caller should
 *              omit the COPY
 *            tel_o is yes if this formula is in tail position
 *            return: the number of bytes needed for this opcode list
 */
static c3_s
_n_comp(u3_noun* ops, c3_o* lev_o, u3_noun fol, c3_o cop_o, c3_o tel_o) {
  c3_s tot_s = 0;
  c3_y op_y;
  u3_noun cod, arg, hed, tel;
  u3x_cell(fol, &cod, &arg);

  if ( c3y == u3du(cod) ) {
    tot_s += _n_two(ops, lev_o, cod, arg, cop_o);
    tot_s += _n_emit(ops, CONS);
  }
  else switch ( cod ) {
    case 0: 
      c3_assert( c3y == u3ud(arg) );
      switch ( arg ) {
        case 0:
          tot_s += _n_emit(ops, BAIL);
          break;
        case 1:
          break;
        case 2:
          tot_s += _n_emit(ops, (c3y == cop_o) ? HELD : HEAD);
          break;
        case 3:
          tot_s += _n_emit(ops, (c3y == cop_o) ? TALL : TAIL);
          break;
        default:
          op_y = (c3y == cop_o)
               ? (arg < 0xFF ? GRAB : arg < 0xFFFF ? GRAS : GRAN)
               : (arg < 0xFF ? FRAG : arg < 0xFFFF ? FRAS : FRAG);
          tot_s += _n_emit(ops, u3nc(op_y, arg));
          break;
      }
      *lev_o = cop_o;
      break;
    case 1: 
      op_y   = (c3y == cop_o) ? QUIP : QUOT;
      tot_s += _n_emit(ops, u3nc(op_y, u3k(arg)));
      *lev_o = cop_o;
      break;
    case 2:
      u3x_cell(arg, &hed, &tel);
      tot_s += _n_two(ops, lev_o, hed, tel, cop_o);
      tot_s += _n_emit(ops, (c3y == tel_o)? NOCT : NOCK);
      break;
    case 3:
      tot_s += _n_comp(ops, tos_o, arg, c3n);
      tot_s += _n_emit(ops, DEEP);
      break;
    case 4:
      tot_s += _n_comp(ops, tos_o, arg, c3n);
      tot_s += _n_emit(ops, BUMP);
      break;
    case 5:
      u3x_cell(arg, &hed, &tel);
      tot_s += _n_two(ops, tos_o, hed, tel);
      tot_s += _n_emit(ops, SAME);
      break;
    case 6: {
      u3_noun mid, tes, yep, nop;
      c3_s yep_s, nop_s, tes_s;
      c3_o ban_o, yep_o, nop_o;

      u3x_trel(arg, &hed, &mid, &tel);

      yep   = u3_nul;
      yep_o = *tos_o;
      yep_s = _n_comp(&yep, &yep_o, mid, tel_o);

      nop   = u3_nul;
      nop_o = yep_o;
      nop_s = _n_comp(&nop, &nop_o, tel, tel_o);

      if ( yep_o == nop_o ) {
        ban_o = yep_o;
      }
      else {
        if ( c3y == yep_o ) {
          u3z(yep);
          yep = u3_nul;
          yep_s = _n_comp(&yep, &n_o, mid, tel_o);
        }
        else {
          u3z(nop);
          nop = u3_nul;
          nop_s = _n_comp(&nop, &n_o, tel, tel_o);
        }
        ban_o = c3n;
      }

      tes   = u3_nul;
      tes_s = ( c3y == ban_o )
            ? _n_comp(&tes, tos_o, hed, c3n)
            : _n_one(&tes, tos_o, hed);

      tot_s += tes_s; _n_apen(ops, tes);
      yep_s += _n_emit(&yep, _n_skip(nop_s));
      tot_s += _n_emit(ops, _n_skin(yep_s));
      tot_s += yep_s; _n_apen(ops, yep);
      tot_s += nop_s; _n_apen(ops, nop);
      break;
    }
    case 7: 
      u3x_cell(arg, &hed, &tel);
      tot_s += _n_comp(ops, tos_o, hed, c3n);
      tot_s += _n_comp(ops, &n_o, tel, tel_o);
      break;
    case 8: {
      u3_noun aft;
      c3_o aft_o;
      u3x_cell(arg, &hed, &tel);

      aft   = u3_nul;
      aft_o = *tos_o;
      tot_s = _n_comp(&aft, &aft_o, tel, tel_o);

      if ( c3y == aft_o ) {
        tot_s += _n_comp(ops, tos_o, hed, c3n);
        tot_s += _n_emit(ops, TOSS);
      }
      else {
        tot_s += _n_one(ops, tos_o, hed);
        tot_s += _n_emit(ops, SNOC);
        *tos_o = c3n;
      }
      _n_apen(ops, aft);
      break;
    }
    case 9:
      u3x_cell(arg, &hed, &tel);
      if ( 3 == u3qc_cap(hed) ) {
        u3_noun mac = u3nq(7, u3k(tel), 2, u3nt(u3nc(0, 1), 0, u3k(hed)));
        tot_s += _n_comp(ops, tos_o, mac, tel_o);
        u3z(mac);
      }
      else {
        tot_s += _n_comp(ops, tos_o, tel, c3n);
        tot_s += _n_emit(ops, u3nc(
              (c3y == tel_o) 
              ? (hed < 0xFF ? TICB : hed < 0xFFFF ? TICS : TICK)
              : (hed < 0xFF ? KICB : hed < 0xFFFF ? KICS : KICK),
              u3k(hed)));
      }
      break;
    case 10:
      u3x_cell(arg, &hed, &tel);
      tot_s += _n_bint(ops, tos_o, hed, tel, tel_o);
      break;
    case 11:
      u3x_cell(arg, &hed, &tel);
      tot_s += _n_two(ops, tos_o, hed, tel);
      tot_s += _n_emit(ops, WISH);
      break;
  }
  return tot_s;
}

static void _n_print_byc(c3_y* pog);

/* _n_asm(): assemble an accumulated list of instructions (i.e. from _n_comp)
 */
static c3_y*
_n_asm(u3_noun ops, c3_s len_s)
{
  u3_noun   top   = ops;
  c3_y*     buf_y = u3a_malloc(sizeof(c3_y) * (len_s+1));
  c3_s      i_s   = len_s;

  buf_y[i_s] = HALT;
  while ( i_s-- > 0 ) {
    u3_noun op = u3h(ops);
    if ( c3y == u3ud(op) ) {
      buf_y[i_s] = (c3_y) u3h(ops);
    }
    else {
      u3_noun cod = u3h(op);
      switch ( cod ) {
        case SBIP:
        case SBIN:
        case KICB:
        case TICB:
        case FRAB:
          buf_y[i_s--] = (c3_y) u3t(op);
          buf_y[i_s]   = (c3_y) cod;
          break;

        case KICS:
        case TICS:
        case FRAS:
        case SKIP:
        case SKIN: {
          c3_s off_s   = u3t(op);
          buf_y[i_s--] = (c3_y) (off_s >> 8);
          buf_y[i_s--] = (c3_y) off_s;
          buf_y[i_s]   = (c3_y) cod;
          break;
        }
        case FRAG:
        case QUOT:
        case QUIP:
        case TICK:
        case KICK: {
          c3_w non_w   = u3k(u3t(op));
          buf_y[i_s--] = (c3_y) (non_w >> 24);
          buf_y[i_s--] = (c3_y) (non_w >> 16);
          buf_y[i_s--] = (c3_y) (non_w >> 8);
          buf_y[i_s--] = (c3_y) non_w;
          buf_y[i_s]   = (c3_y) cod;
          break;
        }
        default:
          c3_assert(0);
      }
    }
    ops = u3t(ops);
  }

  u3z(top);
  return buf_y;
}

/* _n_push(): push a noun onto the stack. RETAIN
 *            mov: -1 north, 1 south
 *            off: 0 north, -1 south
 */
static inline void
_n_push(c3_ys mov, c3_ys off, u3_noun a)
{
  u3R->cap_p += mov;
  u3_noun* p = u3to(u3_noun, u3R->cap_p + off);
  //u3_noun* p = (u3_noun*) u3a_push(sizeof(u3_noun));
  *p = a;
}

/* _n_peek(): pointer to noun at top of stack
 *            off: 0 north, -1 south
 */
static inline u3_noun*
_n_peek(c3_ys off)
{
  return u3to(u3_noun, u3R->cap_p + off);
  //return (u3_noun*) u3a_peek(sizeof(u3_noun));
}

/* _n_peet(): address of the next-to-top of stack
 *            mov: -1 north, 1 south
 *            off: 0 north, -1 south
 */
static inline u3_noun*
_n_peet(c3_ys mov, c3_ys off)
{
  return u3to(u3_noun, (u3R->cap_p - mov) + off);
//  return u3to(u3_noun, u3R->cap_p + (_(u3a_is_north(u3R)) ? 1 : -2));
}

/* _n_pop(): pop a noun from the cap stack
 *           mov: -1 north, 1 south
 */
static inline void
_n_pop(c3_ys mov)
{
  u3R->cap_p -= mov;
}

/* _n_pep(): pop and return noun from the cap stack
 *           mov: -1 north, 1 south
 *           off: 0 north, -1 south
 */
static inline u3_noun
_n_pep(c3_ys mov, c3_ys off)
{
  u3_noun r = *(_n_peek(off));
  _n_pop(mov);
  return r;
}

/* _n_toss(): pep and lose
 */
static inline void
_n_toss(c3_ys mov, c3_ys off)
{
  u3z(_n_pep(mov, off));
}

/* _n_rean(): read a c3_s from the bytecode stream
 */
static inline c3_s
_n_resh(c3_y* buf, c3_s* ip_s)
{
  c3_y les = buf[(*ip_s)++];
  c3_y mos = buf[(*ip_s)++];
  return les | (mos << 8);
}

/* _n_rean(): read a noun from the bytecode stream
 */
static inline u3_noun
_n_rean(c3_y* buf, c3_s* ip_s)
{
  c3_y one = buf[(*ip_s)++],
       two = buf[(*ip_s)++],
       tre = buf[(*ip_s)++],
       qua = buf[(*ip_s)++];
  return one | (two << 8) | (tre << 16) | (qua << 24);
}

/* _n_bite(): compile a nock formula to bytecode
 */
static inline c3_y*
_n_bite(u3_noun fol)
{
  u3_noun bok = u3_nul;
  c3_o tos_o  = c3n;
  c3_s len_s  = _n_comp(&bok, &tos_o, fol, c3y);
  c3_y* buf_y = _n_asm(bok, len_s);
  u3m_p("fol", fol);
  _n_print_byc(buf_y);
  return buf_y;
}

/* _n_find(): return bytecode for given formula. fol is RETAINED.
 */
static inline c3_y*
_n_find(u3_noun fol)
{
  u3_noun got = u3h_get(u3R->byc.har_p, fol);
  if ( u3_none != got ) {
    return u3a_into(got);
  }
  else {
    c3_y* gop = _n_bite(fol);
    got = u3a_outa(gop);
    u3h_put(u3R->byc.har_p, fol, got);
    return gop;
  }
}

typedef struct {
  c3_y* pog;
  c3_s  ip_s;
} burnframe;

/* _n_burn(): pog: program
 *            bus: subject
 *            mov: -1 north, 1 south
 *            off: 0 north, -1 south
 */
static u3_noun
_n_burn(c3_y* pog, u3_noun bus, c3_ys mov, c3_ys off)
{
  /* OPCODE TABLE */
  static void* lab[] = {
    &&do_halt, &&do_copy, &&do_toss,
    &&do_swap, &&do_swat, 
    &&do_skip, &&do_skin,
    &&do_sbip, &&do_sbin,
    &&do_cons, &&do_snoc,
    &&do_head, &&do_tail,
    &&do_frag, &&do_fras, &&do_frab,
    &&do_quot, &&do_quip,
    &&do_nock, &&do_noct,
    &&do_deep, &&do_peep,
    &&do_bump, &&do_same,
    &&do_kick, &&do_kics, &&do_kicb,
    &&do_tick, &&do_tics, &&do_ticb,
    &&do_wish, &&do_fast,
    &&do_cush, &&do_drop,
    &&do_pumo, &&do_gemo,
    &&do_heck, &&do_slog, &&do_bail
  };

  c3_s sip_s, ip_s = 0;
  u3_noun* top;
  u3_noun* up;
  u3_noun x, o;
  u3p(void) empty;
  burnframe* fam;

  empty = u3R->cap_p;
  _n_push(mov, off, bus);

  #define BURN() goto *lab[pog[ip_s++]]
  BURN();
  while ( 1 ) {
    do_halt: 
      x = _n_pep(mov, off);
      if ( empty == u3R->cap_p ) {
        return x;
      }
      else {
        fam  = u3to(burnframe, u3R->cap_p) + off;
        pog  = fam->pog;
        ip_s = fam->ip_s;

        u3R->cap_p = u3of(burnframe, fam - mov);
        _n_push(mov, off, x);
        BURN();
      }

    do_copy:
      top = _n_peek(off);
      _n_push(mov, off, u3k(*top));
      BURN();

    do_toss:
      _n_toss(mov, off);
      BURN();

    do_swap:
      top  = _n_peek(off);
      up   = _n_peet(mov, off);
      x    = *top;
      *top = *up;
      *up  = x;
      BURN();

    do_swat:
      top  = _n_peek(off);
      up   = _n_peet(mov, off);
      x    = *top;
      *top = *up;
      *up  = x;
      _n_toss(mov, off);
      BURN();

    do_skip:
      ip_s += _n_resh(pog, &ip_s);
      BURN();

    do_sbip:
      ip_s += pog[ip_s] + 1;
      BURN();

    do_skin:
      sip_s  = _n_resh(pog, &ip_s);
      goto skin_in;

    do_sbin:
      sip_s  = pog[ip_s++];
    skin_in:
      x      = _n_pep(mov, off);
      if ( c3n == x ) {
        ip_s += sip_s;
      }
      else if ( c3y != x ) {
        u3m_bail(c3__exit);
        return u3_none;
      }
      BURN();

    do_cons:
      x    = _n_pep(mov, off);
      top  = _n_peek(off);
      *top = u3nc(*top, x);
      BURN();

    do_snoc:
      x    = _n_pep(mov, off);
      top  = _n_peek(off);
      *top = u3nc(x, *top);
      BURN();

    do_head:
      top  = _n_peek(off);
      o    = *top;
      if ( c3n == u3du(o) ) {
        u3m_bail(c3__exit);
        return u3_none;
      }
      *top = u3k(u3h(o));
      u3z(o);
      BURN();

    do_tail:
      top  = _n_peek(off);
      o    = *top;
      if ( c3n == u3du(o) ) {
        u3m_bail(c3__exit);
        return u3_none;
      }
      *top = u3k(u3t(o));
      u3z(o);
      BURN();

    do_fras:
      x = _n_resh(pog, &ip_s);
      goto frag_in;

    do_frag:
      x = _n_rean(pog, &ip_s);
      goto frag_in;

    do_frab:
      x    = pog[ip_s++];
    frag_in:
      top  = _n_peek(off);
      o    = *top;
      *top = u3k(u3r_at(x, o));
      u3z(o);
      BURN();

    do_quot:
      _n_toss(mov, off);
    do_quip:
      _n_push(mov, off, u3k(_n_rean(pog, &ip_s)));
      BURN();

    do_nock:
      o    = _n_pep(mov, off);
      x    = _n_pep(mov, off);

      fam        = u3to(burnframe, u3R->cap_p) + off + mov;
      u3R->cap_p = u3of(burnframe, fam);
      fam->ip_s  = ip_s;
      fam->pog   = pog;

      pog  = _n_find(o);
      ip_s = 0;
      u3z(o);
      _n_push(mov, off, x);
      BURN();

    do_noct:
      o    = _n_pep(mov, off);
      pog  = _n_find(o);
      ip_s = 0;
      u3z(o);
      BURN();

    do_deep:
      top  = _n_peek(off);
      o    = *top;
      *top = u3du(o);
      u3z(o);
      BURN();

    do_peep:
      top = _n_peek(off);
      _n_push(mov, off, u3du(*top));
      BURN();

    do_bump:
      top = _n_peek(off);
      o   = *top;
      *top = u3i_vint(o);
      u3z(o);
      BURN();

    do_same:
      x    = _n_pep(mov, off);
      top  = _n_peek(off);
      o    = *top;
      *top = u3r_sing(x, o);
      u3z(x);
      u3z(o);
      BURN();

    do_kics:
      x = _n_resh(pog, &ip_s);
      goto kick_in;
      
    do_kick:
      x = _n_rean(pog, &ip_s);
      goto kick_in;

    do_kicb:
      x    = pog[ip_s++];
    kick_in:
      top  = _n_peek(off);
      o    = *top;
      u3t_off(noc_o);
      *top = u3j_kick(o, x);
      u3t_on(noc_o);
      if ( u3_none == *top ) {
        u3_noun fol = u3r_at(x, o);
        if ( u3_none == fol ) {
          u3m_bail(c3__exit);
          return u3_none;
        }
        _n_pop(mov);

        fam        = u3to(burnframe, u3R->cap_p) + off + mov;
        u3R->cap_p = u3of(burnframe, fam);
        fam->ip_s  = ip_s;
        fam->pog   = pog;

        pog  = _n_find(fol);
        ip_s = 0;
        _n_push(mov, off, o);
      }
      BURN();

    do_tics:
      x = _n_resh(pog, &ip_s);
      goto tick_in;
      
    do_tick:
      x = _n_rean(pog, &ip_s);
      goto tick_in;

    do_ticb:
      x    = pog[ip_s++];
    tick_in:
      top  = _n_peek(off);
      o    = *top;
      u3t_off(noc_o);
      *top = u3j_kick(o, x);
      u3t_on(noc_o);
      if ( u3_none == *top ) {
        u3_noun fol = u3r_at(x, o);
        if ( u3_none == fol ) {
          u3m_bail(c3__exit);
          return u3_none;
        }
        *top = o;
        pog  = _n_find(fol);
        ip_s = 0;
      }
      BURN();

    do_fast: // top->[pro clu]
      top = _n_peek(off);
      up  = _n_peet(mov, off);
      u3t_off(noc_o);
      u3j_mine(*up, u3k(*top));
      u3t_on(noc_o);
      *up = *top;
      _n_pop(mov);
      BURN();

    do_wish:
      top = _n_peek(off);
      up  = _n_peet(mov, off);
      u3t_off(noc_o);
      x   = u3m_soft_esc(*up, u3k(*top));
      u3t_on(noc_o);

      if ( c3n == u3du(x) ) {
        u3m_bail(u3nt(1, *top, 0));
        return u3_none;
      }
      else if ( c3n == u3du(u3t(x)) ) {
        //  replace with proper error stack push
        u3t_push(u3nc(c3__hunk, _n_mush(*top)));
        u3m_bail(c3__exit);
        return u3_none;
      }
      else {
        u3z(*top);
        *top = u3k(u3t(u3t(x)));
        u3z(x);
        BURN();
      }

    do_cush:
      u3t_push(_n_pep(mov, off));
      BURN();

    do_drop:
      u3t_drop();
      BURN();

    do_pumo: // top->[pro key]
      if ( &(u3H->rod_u) != u3R ) {
        top = _n_peek(off);
        up  = _n_peet(mov, off);
        u3z_save(144 + c3__nock, *up, *top);
      }
      BURN();

    do_gemo:
      top  = _n_peek(off);
      x    = u3z_find(144 + c3__nock, *top);
      _n_push(mov, off, (u3_none == x ? 0 : u3nc(0, x)));
      BURN();

    do_heck:
      u3t_off(noc_o);
      u3t_heck(_n_pep(mov, off));
      u3t_on(noc_o);
      BURN();

    do_slog:
      x = _n_pep(mov, off);
      if ( !(u3C.wag_w & u3o_quiet) ) {
        u3t_off(noc_o);
        u3t_slog(x);
        u3t_on(noc_o);
      }
      else {
        u3z(x);
      }
      BURN();

    do_bail:
      u3m_bail(c3__exit);
      return u3_none;
  }
}

static void
_n_print_byc(c3_y* pog)
{
  static char* names[] = {
    "halt", "copy", "toss",
    "swap", "swat", 
    "skip", "skin",
    "sbip", "sbin",
    "cons", "snoc",
    "head", "tail", 
    "frag", "fras", "frab",
    "quot", "quip",
    "nock", "noct",
    "deep", "peep",
    "bump", "same",
    "kick", "kics", "kicb",
    "tick", "tics", "ticb",
    "wish", "fast",
    "cush", "drop",
    "pumo", "gemo",
    "heck", "slog", "bail"
  };
  c3_s ip_s = 0;
  printf("bytecode: {");
  int first = 1;
  while ( pog[ip_s] ) {
    if ( first ) {
      first = 0;
    }
    else {
      printf(" ");
    }
    switch ( pog[ip_s] ) {
      default:
        printf("%s", names[pog[ip_s++]]);
        break;

      case SBIP:
      case SBIN:
      case KICB:
      case TICB:
      case FRAB:
        printf("[%s ", names[pog[ip_s++]]);
        printf("%d]", pog[ip_s++]);
        break;

      case KICS:
      case TICS:
      case FRAS:
      case SKIP:
      case SKIN: 
        printf("[%s ", names[pog[ip_s++]]);
        printf("%d]", _n_resh(pog, &ip_s));
        break;

      case QUOT:
      case QUIP:
      case TICK:
      case FRAG:
      case KICK:
        printf("[%s ", names[pog[ip_s++]]);
        printf("%d]", _n_rean(pog, &ip_s));
        break;
    }
  }
  printf(" halt}\r\n");
}

static void _n_print_stack(u3p(u3_noun) empty) {
  c3_w cur_p = u3R->cap_p;
  printf("[");
  int first = 1;
  while ( cur_p != empty ) {
    if ( first ) {
      first = 0;
    }
    else {
      printf(" ");
    }
    if ( c3y == u3a_is_north(u3R) ) {
      printf("%d", *(u3to(u3_noun, cur_p)));
      cur_p++;
    }
    else {
      printf("%d", *(u3to(u3_noun, cur_p-1)));
      cur_p--;
    }
  }
  printf("]\r\n");
}

/* _n_burn_on(): produce .*(bus fol) with bytecode interpreter
 */
static u3_noun
_n_burn_on(u3_noun bus, u3_noun fol)
{
  c3_y* pog = _n_find(fol);
  c3_ys mov, off;

  u3z(fol);
  if ( c3y == u3a_is_north(u3R) ) {
    mov = -1;
    off = 0;
  }
  else {
    mov = 1;
    off = -1;
  }
  return _n_burn(pog, bus, mov, off);
}

u3_noun
u3n_burn_on(u3_noun bus, u3_noun fol)
{
  u3_noun pro;
  u3t_on(noc_o);
  pro = _n_burn_on(bus, fol);
  u3t_off(noc_o);
  return pro;
}

/* u3n_beep(): promote bytecode state.
*/
void
u3n_beep(u3p(u3h_root) har_p)
{
  u3m_p("beep", 0);
}
