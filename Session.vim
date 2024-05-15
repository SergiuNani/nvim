let SessionLoad = 1
let s:so_save = &g:so | let s:siso_save = &g:siso | setg so=0 siso=0 | setl so=-1 siso=-1
let v:this_session=expand("<sfile>:p")
silent only
silent tabonly
cd ~/AppData/Local/nvim
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
let s:shortmess_save = &shortmess
if &shortmess =~ 'A'
  set shortmess=aoOA
else
  set shortmess=aoO
endif
badd +27 ~/Desktop/Desktop.txt
badd +36 lua/core/keymaps.lua
badd +6 Config.txt
badd +31 lua/plugins/tools/telescope.lua
badd +94 lua/plugins/tools/which-key.lua
badd +1 oil://c:/Users/Sergiu/AppData/Local/nvim//
argglobal
%argdel
$argadd oil://c:/Users/Sergiu/AppData/Local/nvim//
tabnew +setlocal\ bufhidden=wipe
tabrewind
edit lua/core/keymaps.lua
let s:save_splitbelow = &splitbelow
let s:save_splitright = &splitright
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
let &splitbelow = s:save_splitbelow
let &splitright = s:save_splitright
wincmd t
let s:save_winminheight = &winminheight
let s:save_winminwidth = &winminwidth
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
exe 'vert 1resize ' . ((&columns * 117 + 118) / 236)
exe 'vert 2resize ' . ((&columns * 118 + 118) / 236)
argglobal
balt lua/plugins/tools/which-key.lua
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=99
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
1,5fold
119,120fold
154,155fold
let &fdl = &fdl
let s:l = 38 - ((37 * winheight(0) + 25) / 51)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 38
normal! 0
wincmd w
argglobal
if bufexists(fnamemodify("lua/plugins/tools/which-key.lua", ":p")) | buffer lua/plugins/tools/which-key.lua | else | edit lua/plugins/tools/which-key.lua | endif
if &buftype ==# 'terminal'
  silent file lua/plugins/tools/which-key.lua
endif
balt lua/core/keymaps.lua
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=99
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
7,9fold
11,18fold
4,19fold
21,23fold
25,28fold
31,40fold
3,41fold
44,45fold
48,54fold
57,62fold
66,67fold
64,68fold
71,72fold
74,78fold
80,83fold
86,87fold
90,91fold
93,94fold
56,95fold
let &fdl = &fdl
let s:l = 94 - ((42 * winheight(0) + 25) / 51)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 94
normal! 07|
wincmd w
2wincmd w
exe 'vert 1resize ' . ((&columns * 117 + 118) / 236)
exe 'vert 2resize ' . ((&columns * 118 + 118) / 236)
tabnext
edit lua/plugins/tools/which-key.lua
argglobal
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=99
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
8,10fold
12,19fold
5,20fold
22,24fold
26,29fold
32,41fold
4,42fold
45,46fold
49,55fold
58,63fold
67,68fold
65,69fold
72,73fold
75,79fold
81,84fold
87,88fold
91,92fold
94,95fold
57,96fold
let &fdl = &fdl
let s:l = 1 - ((0 * winheight(0) + 26) / 52)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 1
normal! 0
tabnext 1
if exists('s:wipebuf') && len(win_findbuf(s:wipebuf)) == 0 && getbufvar(s:wipebuf, '&buftype') isnot# 'terminal'
  silent exe 'bwipe ' . s:wipebuf
endif
unlet! s:wipebuf
set winheight=1 winwidth=20
let &shortmess = s:shortmess_save
let s:sx = expand("<sfile>:p:r")."x.vim"
if filereadable(s:sx)
  exe "source " . fnameescape(s:sx)
endif
let &g:so = s:so_save | let &g:siso = s:siso_save
set hlsearch
nohlsearch
doautoall SessionLoadPost
unlet SessionLoad
" vim: set ft=vim :
