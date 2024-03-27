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

-----------------==Navigation keymaps==------------------
map("n", "<a-Right>", "<C-i>", { desc = "Move forward in jumps" })
map("n", "<a-Left>", "<C-o>", { desc = "Move backwards in jumps" })
map("n", "<A-d>", "<C-d>zz", { desc = "Move half screen down" })
map("n", "<A-e>", "<C-u>zz", { desc = "Move half screen up" })
-- Move to line beginning and end
map({ 'n', 'v', 'x' }, 'gl', '$', { desc = 'End of line' })
map({ 'n', 'v', 'x' }, 'gh', '^', { desc = 'Beginning of line' })
map("n", "n", "nzzzv", { desc = "Find next but still stay in the middle" })
map("n", "N", "Nzzzv", { desc = "Find prev but still stay in the middle" })
map("n", "<M-q>", "%", { desc = "Jump to tag opposite bracket/tag quickly" })

-----------------==Editing Options==------------------

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

map("n", "<leader>+", "<C-a>", { desc = "Increment number" }) -- increment
map("n", "<leader>-", "<C-x>", { desc = "Decrement number" }) -- decrement

map("n", "<Enter>", "o<ESC>", { desc = "Create new line in normal/insert mode" })


-- map(n",leader>rs",s/\<<C-r><C-w>\>/<C-r><C-w>/gI<Left><Left><Left>]],{ desc = "Repace [W]ord in file " })

------------------==Eazy Life==------------------
map("n", "<leader><leader>", "<cmd>so<cr>", { desc = ":so" })
map("n", "J", "", { desc = "Stop concatinating lines" })
map("n", "<C-a>", "ggVG", { desc = "Clear search highlights" })
map('i', 'jj', '<Esc>', opts)
map({ 'v', 'x','n'}, "x", '"_x', { desc = "Stop copying to clipboard" })
map({ 'v', 'x','n'}, "c", '"_c', { desc = "Stop copying to clipboard" })
map({ 'v', 'x'}, 'p', '"_dP', opts)


-- Better up/down
map('n', 'j', "v:count == 0 ? 'gj' : 'j'", { expr = true, silent = true })
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
