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
badd +190 lua/plugins/tools/telescope.lua
badd +31 lua/plugins/list.lua
badd +1 lua/plugins/tools/projectManager.lua
argglobal
%argdel
$argadd .
edit lua/plugins/list.lua
argglobal
balt lua/plugins/tools/projectManager.lua
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=99
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
2,4fold
1,5fold
18,21fold
16,24fold
13,27fold
28,32fold
33,40fold
45,53fold
43,56fold
57,63fold
64,70fold
73,75fold
71,78fold
79,83fold
86,97fold
84,101fold
103,108fold
109,113fold
114,119fold
123,126fold
121,129fold
132,136fold
130,139fold
140,144fold
149,154fold
146,157fold
10,159fold
163,165fold
167,176fold
179,191fold
193,197fold
let &fdl = &fdl
let s:l = 31 - ((25 * winheight(0) + 25) / 51)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 31
normal! 036|
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
