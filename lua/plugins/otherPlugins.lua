local function load_config(package)
    return function()
        require('plugins.' .. package)
    end
end

local plugins2 = {

    -- ======================== UI components  =======================
    {
        'stevearc/dressing.nvim',
        --Basically wraps UI around renaming/adding files in nvim-tree
        config = load_config('ui.dressing'),
        event = { 'BufReadPre', 'BufNewFile' },
    },
    {
        'windwp/nvim-autopairs',
        config = load_config('lang.autopairs'),
        event = 'InsertEnter',
    },
    {
        'folke/zen-mode.nvim',
        event = { 'BufReadPre', 'BufNewFile' },
        config = load_config('ui.zen-mode'),
    },

    { -- Search text and if color => show color
        "NvChad/nvim-colorizer.lua",
        event = { "BufReadPre", "BufNewFile" },
        config = true,
    },
    {
        'HiPhish/rainbow-delimiters.nvim',
        config = load_config('ui.rainbow'),
        event = { 'BufReadPre', 'BufNewFile' },
    },
    {
        'nvim-tree/nvim-tree.lua',
        dependencies = {
            'nvim-tree/nvim-web-devicons',
        },
        config = load_config('tools.nvim-tree'),
        cmd = 'NvimTreeToggle',
    },
    {
        '2kabhishek/termim.nvim', -- For lazyGit
        cmd = { 'Fterm', 'FTerm', 'Sterm', 'STerm', 'Vterm', 'VTerm' },
    },
    {
        'lewis6991/gitsigns.nvim',
        cmd = 'Gitsigns',
        config = load_config('tools.gitsigns'),
        event = { 'VimEnter' },
    },
    {
        "shellRaining/hlchunk.nvim",
        event = { "UIEnter" },
        config = load_config('ui.hlchunk'),
    },

    -- { -- This or hlchunk not both
    --     'lukas-reineke/indent-blankline.nvim',
    --     config = load_config('ui.indentline'),
    --     main = 'ibl',
    --     event = { 'BufReadPre', 'BufNewFile' },
    -- },
    --
    {
        "folke/todo-comments.nvim",
        event = { "BufReadPre", "BufNewFile" },
        dependencies = { "nvim-lua/plenary.nvim" },
        config = load_config('ui.todo-comments'),
    },
    -- ======================== Tricks  =======================
    --
    {
        "LintaoAmons/bookmarks.nvim",
        dependencies = {
            { "stevearc/dressing.nvim" }
        },
        -- branch = 'main',
        config = load_config('ui.bookmarks'),
        event = { 'BufReadPre', 'BufNewFile' },
    },
    {
        "szw/vim-maximizer",
        event = { "BufReadPre", "BufNewFile" },
    },
    {
        "rmagatti/auto-session",
        config = load_config('ui.auto-session'),
        event = { 'VimEnter' },
    },
    {
        "stevearc/conform.nvim",
        config = load_config('lang.formatter'),
        event = { 'BufReadPre', 'BufNewFile' },
        lazy = true,
    },
    -- ======================== SuperExtra  =======================

    -- {
    --     'm4xshen/hardtime.nvim',
    --     dependencies = { 'MunifTanjim/nui.nvim', 'nvim-lua/plenary.nvim' },
    --     config = function()
    --         require('hardtime').setup({ enabled = true })
    --     end,
    --     cmd = 'Hardtime',
    -- },
    -- {
    --     "https://github.com/ThePrimeagen/vim-be-good",
    --     event = 'UIEnter',
    -- },

    -- {
    --     'zbirenbaum/copilot.lua',
    --     dependencies = {
    --         'zbirenbaum/copilot-cmp',
    --     },
    --     config = load_config('lang.copilot'),
    --     event = 'InsertEnter',
    -- },


    -- {
    --     'folke/flash.nvim',
    --     config = load_config('tools.flash'),
    --     keys = {
    --         {
    --             's',
    --             mode = { 'n', 'x', 'o' },
    --             function()
    --                 require('flash').jump()
    --             end,
    --             desc = 'Flash',
    --         },
    --         {
    --             'S',
    --             mode = { 'n', 'x', 'o' },
    --             function()
    --                 require('flash').treesitter()
    --             end,
    --             desc = 'Flash Treesitter',
    --         },
    --     },
    -- },

}


return { plugins2 = plugins2 }
