local lspsaga = require('lspsaga')

local icons = require('lib.icons')

lspsaga.setup({
    rename = {
        auto_save = true,
    },
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

map('n', '<F12>', "<cmd>Lspsaga goto_definition<cr>", { desc = "Goto Type Definition" })
map('n', 'gd', "<cmd>Lspsaga goto_definition<cr>", { desc = "Goto Type Definition" })
map('n', '<S-F12>', "<cmd>Telescope lsp_references<cr>", { desc = "References" })
map('n', '<M-F12>', "<cmd>Lspsaga peek_definition<cr>", { desc = "Peek Type Definition" })
map('n', 'gr', "<cmd>Lspsaga finder<cr>", { desc = "Find references in Telescope" })


map('n', '<A-i>', vim.lsp.buf.hover, { desc = "Show doc under the cursor" })
map('n', '<leader>fd', "<cmd>Lspsaga show_workspace_diagnostics<cr>", { desc = "Workspace Diagnostics" })
map('n', '[d', vim.diagnostic.goto_prev, { desc = "Jump to prev Diagnostic" })
map('n', ']d', vim.diagnostic.goto_next, { desc = "Jump to next Diagnostic" })


-- Not popular
map('n', '<leader>li', "<cmd>LspInfo<cr>", { desc = "LSP Info" })
map('n', '<leader>la', "<cmd>Lspsaga code_action<cr>", { desc = "Code Action" })
map('n', '<leader>lo', "<cmd>Lspsaga outline<cr>", { desc = "Show LSP outline" })
map('n', '<leader>le', "<cmd>LspStart<cr>", { desc = "LSP Enable" })
map('n', '<leader>lt', "<cmd>Telescope diagnostics<cr>", { desc = "Telescope Diagnostics" })
map('n', '<leader>ld', "<cmd>LspStop<cr>", { desc = "LSP Disable" })
map('n', '<leader>lr', "<cmd>LspRestart<cr>", { desc = "LSP Restart" })
