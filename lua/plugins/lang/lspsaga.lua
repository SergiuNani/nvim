local lspsaga = require('lspsaga')

local icons = require('lib.icons')

lspsaga.setup({
    ui = {
        theme = 'round',
        border = 'rounded',
        devicon = true,
        title = true,
        winblend = 1,
        expand = icons.ui.ArrowOpen,
        collapse = icons.ui.ArrowClosed,
        preview = icons.ui.List,
        code_action = icons.diagnostics.Hint,
        diagnostic = icons.ui.Bug,
        incoming = icons.ui.Incoming,
        outgoing = icons.ui.Outgoing,
        hover = icons.ui.Comment,
    },
})

local function map(mode, lhs, rhs, opts)
    opts = opts or {}
    opts.silent = opts.silent ~= false
    vim.keymap.set(mode, lhs, rhs, opts)
end
local opts = { noremap = true, silent = true }
--L SPsaga Finder: o -open, s-split

map('n', '<F12>', "<cmd>Lspsaga goto_definition<cr>", {desc ="Goto Type Definition"})
map('n', '<S-F12>', "<cmd>Telescope lsp_references<cr>", {desc ="References"})
map('n', '<M-F12>', "<cmd>Lspsaga peek_definition<cr>", {desc ="Peek Type Definition"})
map('n', 'gr', "<cmd>Lspsaga finder<cr>", {desc ="Find references in Telescope"})


map('n', '<leader>la', "<cmd>Lspsaga code_action<cr>", {desc ="Code Action"})
map('n', '<leader>ld',"<cmd>Telescope diagnostics<cr>", {desc ="Diagnostics"})
map('n', '<leader>fd', "<cmd>Lspsaga show_workspace_diagnostics<cr>", {desc ="Workspace Diagnostics"})
map('n', '<leader>li', "<cmd>LspInfo<cr>", {desc ="LSP Info"})
-- map('n', '<leader>l', "<cmd>Lspsaga rename<cr>", {desc ="Rename"})
-- map('n', '<leader>l', "<cmd>Lspsaga project_replace<cr>", {desc ="Replace"})





