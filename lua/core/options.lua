-- -- Highlight tml files like C files
--
vim.cmd("autocmd BufNewFile,BufRead *.tml,*.cfg,*.cp set ft=c")
vim.cmd("let g:netrw_liststyle = 3")

-- vim.cmd(":set relativenumber")
-- vim.cmd(":set <S-Down>=^[[1;2B")

vim.g.have_nerd_font = true
vim.opt.showmode = false

local opt = vim.opt -- for conciseness
opt.fillchars = { fold = " " }

-- BSSSSSSSSSSSSSSSSSSSSS =======================
opt.foldmethod = "indent"
opt.foldcolumn = '0'
opt.foldlevel = 99
opt.foldlevelstart = 99
opt.foldenable = true
-- opt.foldopen = block
-- BSSSSSSSSSSSSSSSSSSSSS =======================

opt.background = "dark" -- colorschemes that can be light or dark will be made dark

local options = {
    ai = true,
    autoindent = true,
    autowrite = true,
    backspace = 'indent,eol,start',
    backup = false,                        -- creates a backup file
    breakindent = true,
    clipboard = 'unnamedplus',             -- allows neovim to access the system clipboard
    cmdheight = 1,                         -- more space in the neovim command line for displaying messages
    completeopt = 'menu,menuone,noselect', -- mostly just for cmp
    -- conceallevel = 0, -- so that `` is visible in markdown files
    confirm = true,                        -- Confirm to save changes before exiting modified buffer
    cursorline = true,                     -- highlight the current line
    expandtab = true,                      -- convert tabs to spaces
    fileencoding = 'utf-8',                -- the encoding written to a file
    formatoptions = 'jlnqt',               -- set formatoptions, check help fo-table
    grepformat = '%f:%l:%c:%m',
    grepprg = 'rg --vimgrep',
    hlsearch = true, -- highlight all matches on previous search pattern
    ignorecase = true, -- ignore case in search patterns
    smartcase = false, -- smart case
    inccommand = 'split', -- preview incremental substitute
    laststatus = 3,
    listchars = { trail = '', tab = '', nbsp = '%', extends = '>', precedes = '<', eol = '$' }, -- highlight
    -- list = true, --This is the genius parameter which sets the markings of empty characters etc
    mouse = 'a', -- allow the mouse to be used in neovim
    number = true, -- set numbered lines
    relativenumber = true, -- set relative numbered lines
    numberwidth = 4, -- set number column width to 2 {default 4}
    pumblend = 10, -- Popup blen
    pumheight = 10, -- pop up menu height
    scrolloff = 4, -- is one of my fav
    sessionoptions = 'blank,buffers,curdir,folds,help,tabpages,winsize,winpos,terminal',
    shiftround = true, -- Round indent
    shiftwidth = 4, -- the number of spaces inserted for each indentation --maybe set it to 2
    showcmd = false,
    showmode = false, -- we don't need to see things like -- INSERT -- anymore
    showtabline = 0, -- always show tabs
    si = true,
    sidescrolloff = 8,
    signcolumn = 'yes',             -- always show the sign column, otherwise it would shift the text each time
    smartindent = true,             -- make indenting smarter again
    smarttab = true,
    splitbelow = true,              -- force all horizontal splits to go below current window
    splitright = true,              -- force all vertical splits to go to the right of current window
    swapfile = false,               -- creates a swapfile
    tabstop = 2,                    -- insert 2 spaces for a tab
    termguicolors = true,           -- set term gui colors (most terminals support this)
    timeoutlen = 300,               -- time to wait for a mapped sequence to complete (in milliseconds)
    undofile = false,               -- enable persistent undo
    undolevels = 10000,
    updatetime = 750,               -- faster completion (4000ms default)
    wildmenu = true,                -- wildmenu
    wildmode = 'longest:full,full', -- Command-line completion mode
    winminwidth = 5,                -- Minimum window width
    wrap = false,                   -- display lines as one long line
    writebackup = false,            -- do not edit backups
    fileformats = 'dos',

}
for k, v in pairs(options) do
    vim.opt[k] = v
end

-- vim.cmd([[
--      setlocal spell spelllang=en "Set spellcheck language to en
--      setlocal spell! "Disable spell checks by default
--      filetype plugin indent on
--      if has('win32')
--         let g:python3_host_prog = $HOME . '/scoop/apps/python/current/python.exe'
--      endif
--  ]])

vim.opt.path:append({ '**' })

-- Undercurl
vim.cmd([[let &t_Cs = "\e[4:3m"]])
vim.cmd([[let &t_Ce = "\e[4:0m"]])

vim.opt.shortmess:append({ W = true, I = true, c = true })

if vim.fn.has('nvim-0.9.0') == 1 then
    vim.opt.splitkeep = 'screen'
    vim.opt.shortmess:append({ C = true })
end
-- Fix markdown indentation settings
vim.g.markdown_recommended_style = 0

--If you want the arrows to cross the next line , otherwise it will be blocked
-- vim.cmd('set whichwrap+=<,>,[,],h,l')

-- vim.cmd([[set iskeyword+=-]])
