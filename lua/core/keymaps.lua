local function map(mode, lhs, rhs, opts)
    opts = opts or {}
    opts.silent = opts.silent ~= false
    vim.keymap.set(mode, lhs, rhs, opts)
end
local opts = { noremap = true, silent = true }

-- Space as leader
map('n', '<Space>', '', opts)
vim.g.mapleader = ' '
vim.g.maplocalleader = ' '


-- ============================== Easy Life ==============================
--
map("n", "<leader><leader>", "<cmd>so<cr>", { desc = ":so" })
map({ 'v', 'x', 'n' }, "x", '"_x', { desc = "Stop copying to clipboard" })
map({ 'v', 'x', 'n' }, "X", '"_X', { desc = "Stop copying to clipboard" })
map({ 'v', 'x', 'n' }, "c", '"_c', { desc = "Stop copying to clipboard" })
map({ 'v', 'x', 'n' }, "C", '"_C', { desc = "Stop copying to clipboard" })
map("n", "<C-a>", "ggVG", { desc = "Clear search highlights" })
-- map("n", "<C-w>", "<cmd>:q!<CR>", { desc = "Close buffer" })
map({ 'v', 'x' }, "y", 'y`]', { desc = "Yank text but the cursor back on the last line not first" })
-- map({ 'v', 'x' }, 'p', 'pgv`]', opts)

map('i', 'jj', '<Esc>', opts)
map('i', 'kk', '<Esc>', opts)

map("n", "n", "nzzzv", { desc = "Find next but still stay in the middle" })
map("n", "N", "Nzzzv", { desc = "Find prev but still stay in the middle" })
map("n", "<A-z>", "<cmd>set wrap!<CR>", { desc = "Toggle Word Wrap" })
map("v", "<C-c>", "y", { desc = "Copy text" })
map("n", "<C-c>", 'yy', { desc = "Copy text" })

map("n", "<leader>yy", '<cmd>%y+<cr>', { desc = "Copy full file" })
map("n", "<leader>yp", '<cmd>CApath<cr>', { desc = "Copy Absolute Path" })
map("n", "<leader>yP", '<cmd>CRpath<cr>', { desc = "Copy Relative Path" })

-- ============================== Window Management ==============================
map("n", "<leader>q", "<cmd>x<cr>", { desc = "Quit and save" })
map("n", "<leader>Q", "<cmd>qa!<cr>", { desc = "Force quit and dont save" })
map("n", "<leader>w", "<cmd>w<cr>", { desc = "Save" })
map("n", "<leader>x", "<cmd>q<cr>", { desc = "Quit, don`t save" })


map("n", "<leader>ss", "<cmd>vsplit<cr>", { desc = "Vertical Split File" })
map("n", "<leader>sv", "<cmd>vsplit<cr>", { desc = "Vertical Split File" })
map("n", "<leader>sh", "<cmd>split<cr>", { desc = "Horizontal Split File" })
map("n", "<leader>se", "<C-w>=", { desc = "Make splits equal size" })
map("n", "<leader>sm", "<cmd>MaximizerToggle<CR>", { desc = "Toggle full zoom split" })

map("n", "<C-h>", "<C-w>h", { desc = "Move Left" })
map("n", "<C-j>", "<C-w>j", { desc = "Move Down" })
map("n", "<C-k>", "<C-w>k", { desc = "Move Up" })
map("n", "<C-l>", "<C-w>l", { desc = "Move Right" })


map("n", "<C-A-Up>", "<cmd>resize +10<cr>", { desc = "Increase window height" })
map("n", "<C-A-Down>", "<cmd>resize -10<cr>", { desc = "Decrease window height" })
map("n", "<C-A-Right>", "<cmd>vertical resize +10<cr>", { desc = "Increase window width" })
map("n", "<C-A-Left>", "<cmd>vertical resize -10<cr>", { desc = "Decrease window width" })

--WorkSpace
map("n", "<C-n>", "<cmd>tabnew<cr>", { desc = "Create a new file/workingspace" })
map("n", "<C-M-q>", "<cmd>tabclose<cr>", { desc = "Close current workspace" })
map("n", "J", "<cmd>tabnext<cr>", { desc = "Next working space" })
map("n", "K", "<cmd>tabprevious<cr>", { desc = "Next working space" })
map("n", "<s-j>", "<cmd>tabnext<cr>", { desc = "goto prev buffer" })
map("n", "<s-k>", "<cmd>tabprevious<cr>", { desc = "goto next buffer" })
-- ============================== Navigation Keymaps ==============================

map("n", "gh", "H", { desc = "go High" })
map("n", "gl", "L", { desc = "go Low" })
map("n", "gm", "M", { desc = "go Middle" })
map("n", "gt", "%", { desc = "goto tag" })
map("v", "gt", "%", { desc = "goto tag" })

map("n", "<A-d>", "<C-d>zz", { desc = "Move half screen down" })
map("n", "<A-e>", "<C-u>zz", { desc = "Move half screen up" })
map("n", "<a-Right>", "<C-i>", { desc = "Move forward in jumps" })
map("n", "<a-Left>", "<C-o>", { desc = "Move backwards in jumps" })

map("n", "<s-l>", "$", { desc = "goto end of line" })
map("n", "<s-h>", "^", { desc = "goto beginning of line" })
map("n", "L", "$", { desc = "goto end of line" })
map("n", "H", "^", { desc = "goto beginning of line" })

map("i", "<C-h>", "<Left>", { desc = "Left" })
map("i", "<C-l>", "<Right>", { desc = "Right" })
map("i", "<C-j>", "<Down>", { desc = "Down" })
map("i", "<C-k>", "<Up>", { desc = "Up" })

map("i", "<C-A-h>", "<C-o>b", { desc = "Skip forward word in InsetMode" })
map("i", "<C-A-l>", "<C-o>e<right>", { desc = "Skip backwards word in InsetMode" })

map("i", "<C-A-j>", "<Esc>I", { desc = "goto start of line in Insert mode" })
map("i", "<C-A-k>", "<Esc>A", { desc = "goto end of line in Insert mode" })


-- ============================== Editing Keymaps ==============================


-- Duplicate line or block
-- map('n', '<C-A-j>', "yyp", opts)
map('n', '<C-A-j>', '"ayy"ap', opts)
map('n', '<C-A-k>', '"ayy"aP', opts)
map('v', '<C-A-j>', "yPgv", opts)
map('v', '<C-A-k>', "yPgv", opts)

map('n', '<leader>d', "cc<ESC>", opts)
map('n', '<leader>D', "ggdG", opts)

map('n', '<A-j>', ":m .+1<CR>==", opts)
map('n', '<A-k>', ":m .-2<CR>==", opts)
map('i', '<A-k>', "<Esc>:m .-2<CR>==gi", opts)
map('i', '<A-j>', "<Esc>:m .+1<CR>==gi", opts)
map({ 'v', 'x' }, '<A-j>', ":move '>+1<CR>gv=gv", opts)
map({ 'v', 'x' }, '<A-k>', ":move '<-2<CR>gv=gv", opts)

map('n', '<A-Down>', ":m .+1<CR>==", opts)
map('n', '<A-Up>', ":m .-2<CR>==", opts)
map('i', '<A-Down>', "<Esc>:m .+1<CR>==gi", opts)
map('i', '<A-Up>', "<Esc>:m .-2<CR>==gi", opts)
map({ 'v', 'x' }, '<A-Down>', ":move '>+1<CR>gv=gv", opts)
map({ 'v', 'x' }, '<A-Up>', ":move '<-2<CR>gv=gv", opts)


map("n", "<Enter>", "o<ESC>", { desc = "Create new line in normal/insert mode" })

map("n", "<Leader>i1", "i<C-O>40i=<ESC>i<Space><Space><C-O>40i=<Esc>b<Left>",
    { desc = "Insert line of ====" })
map("n", "<Leader>i2", "i<C-O>30i=<ESC>i<Space><Space><C-O>30i=<Esc>b<Left>",
    { desc = "Insert line of ====" })
map("n", "<Leader>i3", "i<C-O>20i=<ESC>i<Space><Space><C-O>20i=<Esc>b<Left>",
    { desc = "Insert line of ====" })
map("n", "<Leader>i4", "i<C-O>10i=<ESC>i<Space><Space><C-O>10i=<Esc>b<Left>",
    { desc = "Insert line of ====" })

map("n", "gJ", ":s/ \\([a-zA-Z0-9]\\)/\\r\\1/g<CR>:noh<CR>")

map("n", "Q", "@q")
map("x", "Q", ":norm @q<CR>")
-- ============================== Other ==============================

-- map("n", "<C-Enter>", "o<ESC>", { desc = "Create new line in normal/insert mode" }) --Dont work
-- map("n", "<S-Enter>", "O<ESC>", { desc = "Create new line in normal/insert mode" })

map("i", "<C-Del>", "<esc>lce", { desc = "Delete forward" })
map("i", "<C-BS>", "<esc>lcb", { desc = "Delete forward" })
map("i", "<A-Del>", "<esc>lce", { desc = "Delete forward" })
map("i", "<A-BS>", "<C-w>", { desc = "Delete forward" })

map("n", "<leader>+", "<C-a>", { desc = "Increment number" }) -- increment
map("n", "<leader>-", "<C-x>", { desc = "Decrement number" }) -- decrement
map('x', '<leader>+', 'g<C-a>', { desc = "Increment recursivly in X mode" })
map('x', '<leader>-', 'g<C-x>', { desc = "Decrement recursivly in X mode" })

-- Better up/down
map('n', 'j', "v:count == 0 ? 'gj' : 'j'", { expr = true, silent = true }) -- in case of wraped text you go line by line
map('n', 'k', "v:count == 0 ? 'gk' : 'k'", { expr = true, silent = true })

-- Clear search, diff update and redraw
map({ 'i', 'n' }, '<esc>', '<cmd>noh<cr><esc>', { desc = 'Escape and clear hlsearch' })


-- Better indenting
map('v', '<', '<gv')
map('v', '>', '>gv')

-- Add undo breakpoints
map('i', ',', ',<c-g>u')
map('i', '.', '.<c-g>u')
map('i', ';', ';<c-g>u')


map("n", "<leader>rf", [[:cfdo %s/<C-r><C-w>/<C-r><C-w>/g | update <C-Left><C-Left><Left><Left><Left>]],
    { desc = "Replace in quickList" })
map("n", "<leader>rb", [[:%s/\<<C-r><C-w>\>/<C-r><C-w>/gI<Left><Left><Left>]], { desc = "Replace in buffer" })
map('n', '<leader>rr', "<cmd>Lspsaga rename<cr>", { desc = "Rename via LSP" })



-- //Change current file

map("n", "<leader>cf", "<cmd>lua vim.lsp.buf.format({async = true})<cr>", { desc = "Format files" })
map("n", "<leader>ce", [[<cmd>:%s/^\n\+/\r<cr>]], { desc = "Clean Empty Lines" })
map("n", "<leader>ct", [[<cmd>:%s/\t/ /g<cr>]], { desc = "Replace tabs with spaces" })
map("n", "<leader>cd", [[<cmd>:%s/^\(.*\)\(\n\1\)\+$/\2<cr>]], { desc = "Leave a specific nr of lines" })

map("n", "<leader>cm", "<cmd>e<cr>", { desc = "Remove ^M by Updating buffer" })
map("n", "<leader>cn", "<cmd>set relativenumber!<cr>", { desc = "Relative Numbers" })
map("n", "<leader>cr", "<cmd>Telescope reloader<cr>", { desc = "Reload Module" })
map("n", "<leader>cR", "<cmd>ReloadConfig<cr>", { desc = "Reload Configs" })


-- Function to toggle 'list' setting
map('n', '<leader>cl', '<cmd>ToggleList<CR>', { desc = "toggle list" })

map("n", "<leader>mm", "<cmd>MaximizerToggle<CR>", { desc = "Toggle current window in full view" })



--:%s/\r//g                   : Dellete DOS returns ^M
--
--:%s/\r/\r/g                 : Turn DOS returns ^M into real returns
--
--:g/fred.*joe.*dick/         : display all lines fred,joe & dick
--
--das                                   : delete a sentence
--
--diB   daB                             : Empty a function {}
--
--
--nnoremap <leader>sn ]s " Go to next misspelled word
--nnoremap <leader>sp [s " Go to previous misspelled word
--map <leader>sa zg " Add word under cursor to the good words file
--nnoremap <leader>s? z=  " Suggest correct word for word under the cursor
-- " Insert commented horizontal line
--
--
