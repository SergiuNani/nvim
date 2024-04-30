local treesitter = require('nvim-treesitter.configs')
local textobjects = require('plugins.lang.textobjects')

local disable_function = function(lang)
    local buf_name = vim.fn.expand("%")
    if string.find(buf_name, "vars_legacy") then
        return true
    end
end

local installed_parsers = {}
local auto_install = require('lib.util').get_user_config('auto_install', true)
if auto_install then
    installed_parsers = require('plugins.list').ts_parsers
end

treesitter.setup({
    ensure_installed = installed_parsers,
    sync_install = false,
    ignore_install = {},
    auto_install = false,

    textobjects = textobjects,
    autopairs = { enable = true },
    autotag = { enable = true },
    matchup = { enable = true },
    indent = { enable = true },

    highlight = {
        enable = true,
        disable = disable_function,
        additional_vim_regex_highlighting = false,
    },

    incremental_selection = {
        enable = true,
        keymaps = {
            init_selection = '<M-a>',
            node_incremental = '<M-a>',
            scope_incremental = false,
            node_decremental = '<M-q>',
        },
    },

    textsubjects = {
        enable = true,
        prev_selection = ',',
        keymaps = {
            ['.'] = { 'textsubjects-smart', desc = 'Select the current text subject' },
            ['a;'] = {
                'textsubjects-container-outer',
                desc = 'Select outer container (class, function, etc.)',
            },
            ['i;'] = {
                'textsubjects-container-inner',
                desc = 'Select inside containers (classes, functions, etc.)',
            },
        },
    },

})

local function toggle_treesitter()
    local buf = vim.api.nvim_get_current_buf()
    local highlighter = require("vim.treesitter.highlighter")
    if highlighter.active[buf] then
        -- Tree-sitter highlighting is enabled, so we want to disable it
        vim.notify('Tree-sitter disabled!', vim.log.levels.INFO)
        vim.cmd(":TSBufDisable highlight ")
        vim.cmd(":TSBufDisable autopairs ")
        vim.cmd(":TSBufDisable autotag ")
        vim.cmd(":TSBufDisable matchup ")
        vim.cmd(":TSBufDisable indent ")
        vim.cmd(":TSBufDisable refactor ")
        vim.cmd(":TSBufDisable incremental_selection ")
        vim.cmd(":TSBufDisable  textsubjects")
    else
        -- Tree-sitter highlighting is disabled, so we want to enable it
        vim.notify('Tree-sitter enabled!', vim.log.levels.INFO)
        vim.cmd(":TSBufEnable highlight ")
        vim.cmd(":TSBufEnable autopairs ")
        vim.cmd(":TSBufEnable autotag ")
        vim.cmd(":TSBufEnable matchup ")
        vim.cmd(":TSBufEnable indent ")
        vim.cmd(":TSBufEnable refactor ")
        vim.cmd(":TSBufEnable incremental_selection ")
        vim.cmd(":TSBufEnable  textsubjects")
    end
end

local function Toggle_performance()
    local buf = vim.api.nvim_get_current_buf()
    local highlighter = require("vim.treesitter.highlighter")
    if highlighter.active[buf] then
        vim.notify('Max_Performance. TreeSitter and LSP disabled!', vim.log.levels.INFO)
        vim.cmd(":TSBufDisable highlight ")
        vim.cmd(":TSBufDisable autopairs ")
        vim.cmd(":TSBufDisable autotag ")
        vim.cmd(":TSBufDisable matchup ")
        vim.cmd(":TSBufDisable indent ")
        vim.cmd(":TSBufDisable refactor ")
        vim.cmd(":TSBufDisable incremental_selection ")
        vim.cmd(":TSBufDisable  textsubjects")
        vim.cmd(":LspStop")
    else
        vim.notify('Normal mode. TreeSitter and LSP enabled!', vim.log.levels.INFO)
        vim.cmd(":TSBufEnable highlight ")
        vim.cmd(":TSBufEnable autopairs ")
        vim.cmd(":TSBufEnable autotag ")
        vim.cmd(":TSBufEnable matchup ")
        vim.cmd(":TSBufEnable indent ")
        vim.cmd(":TSBufEnable refactor ")
        vim.cmd(":TSBufEnable incremental_selection ")
        vim.cmd(":TSBufEnable  textsubjects")
        vim.cmd(":LspStart")
    end
end

vim.api.nvim_create_user_command('ToggleTS', toggle_treesitter, {})
vim.api.nvim_create_user_command('TogglePerformance', Toggle_performance, {})
local keymap = vim.keymap -- for conciseness
keymap.set("n", "<leader>pp", "<cmd>TogglePerformance<CR>", { desc = "Toggle Performance" })
keymap.set("n", "<leader>tt", "<cmd>ToggleTS<CR>", { desc = "TSBufToggle" })
keymap.set("n", "<leader>te", "<cmd>TSBufEnable highlight<CR>", { desc = "TSEnable highlight" })
keymap.set("n", "<leader>td", "<cmd>TSBufDisable highlight<CR>", { desc = "TSBufDisable" })
