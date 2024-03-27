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


vim.keymap.set('n', '<F12>', "<cmd>Lspsaga goto_type_definition<cr>", {desc ="Goto Type Definition"})
vim.keymap.set('n', '<S-F12>', "<cmd>Telescope lsp_references<cr>", {desc ="References"})
vim.keymap.set('n', '<M-F12>', "<cmd>Lspsaga peek_type_definition<cr>", {desc ="Peek Type Definition"})
