local function load_config(package)
    return function()
        require('plugins.' .. package)
    end
end

-- Uncomment the line below to load only the nexessary plugins
local plugins2 = require('plugins.otherPlugins').plugins2
-- local plugins2 = {}
local plugins = {
    ---- ======================== first priority  =======================
    -- Telescope
    {
        'nvim-telescope/telescope.nvim',
        branch = '0.1.x',
        dependencies = {
            'nvim-lua/plenary.nvim',
            {
                'nvim-telescope/telescope-fzf-native.nvim',
                build = 'make',
            },
            'molecule-man/telescope-menufacture', --?? needs exploration
        },
        config = load_config('tools.telescope'),
        cmd = 'Telescope',
    },
    {
        'stevearc/oil.nvim',
        opts = {},
        -- optional dependencies
        dependencies = { "nvim-tree/nvim-web-devicons" },
        config = load_config('ui.oil'),
        event = { 'vimenter' },
    },

    --  Completion ----------------
    {
        'hrsh7th/nvim-cmp',
        dependencies = {
            'hrsh7th/cmp-buffer',
            'hrsh7th/cmp-path',
            'hrsh7th/cmp-cmdline',
            'hrsh7th/cmp-nvim-lua',
            'L3MON4D3/LuaSnip',
            'rafamadriz/friendly-snippets',
            'saadparwaiz1/cmp_luasnip',
        },
        config = load_config('lang.cmp'),
        event = 'InsertEnter',
    },
    {
        'ThePrimeagen/harpoon',
        branch = 'harpoon2',
        config = load_config('tools.harpoon'),
        event = { 'BufReadPre', 'BufNewFile', 'VimEnter' },
        priority = 1000,
    },
    {
        'echasnovski/mini.comment',
        version = '*',
        dependencies = 'JoosepAlviste/nvim-ts-context-commentstring',
        config = load_config('lang.comment'),
        event = { 'BufReadPre', 'BufNewFile' },
    },
    {
        "kevinhwang91/nvim-ufo", --Folding options
        dependencies = {
            "kevinhwang91/promise-async",
        },
        config = load_config('tools.ufo'),
        event = { 'VimEnter', 'BufNewFile' },
    },
    {
        'folke/which-key.nvim',
        config = load_config('tools.which-key'),
        event = 'VeryLazy',
    },
    {
        "folke/tokyonight.nvim",
        dependencies = {
            "shatur/neovim-ayu",
            'navarasu/onedark.nvim',
            "ellisonleao/gruvbox.nvim", --7/10
            -- "bluz71/vim-nightfly-guicolors",--ehh
            -- 'olimorris/onedarkpro.nvim',
            -- "rebelot/kanagawa.nvim", --5/10
            -- "ribru17/bamboo.nvim", --6/10
            -- "rose-pine/neovim", --3/10
            -- "marko-cerovac/material.nvim", --2/10
        },
        config = load_config('ui.colorscheme'),
        lazy = false,
        priority = 1000,
    },
    -- ======================== Secondary Priority  =======================
    {
        'rcarriga/nvim-notify',
        config = load_config('ui.notify'),
        event = 'VeryLazy',
        cmd = 'Notifications',
    },
    {
        'nvim-lualine/lualine.nvim',
        config = load_config('ui.lualine'),
        event = { 'BufReadPre', 'BufNewFile' },
    },
    {
        'kylechui/nvim-surround',
        version = '*',
        config = load_config('lang.surround'),
        event = "VeryLazy",
    },
    -- {
    --     'echasnovski/mini.surround',
    --     version = '*',
    --     config = load_config('lang.surround'),
    --     event = { 'BufReadPre', 'BufNewFile' },
    -- },
    -- --  ----------------LSP ----------------
    {
        'williamboman/mason.nvim',
        dependencies = {
            "williamboman/mason-lspconfig.nvim",
            "WhoIsSethDaniel/mason-tool-installer.nvim",
        },
        config = load_config('lang.mason'),
        cmd = 'Mason',
    },
    {
        'neovim/nvim-lspconfig',
        dependencies = {
            { "antosha417/nvim-lsp-file-operations", config = true },
            { "j-hui/fidget.nvim",                   opts = {} }, -- Right bottom corner when enter it shows the %  of LSP
            { 'hrsh7th/cmp-nvim-lsp',                opts = {} },
        },
        config = load_config('lang.lspconfig'),
        event = { 'BufReadPre', 'BufNewFile' },
    },
    {
        'nvimdev/lspsaga.nvim',
        config = load_config('lang.lspsaga'),
        event = 'LspAttach',
    },
    -- ======================== Third Priority =======================
    {
        'nvim-treesitter/nvim-treesitter',
        build = ':TSUpdate',
        dependencies = {
            'nvim-treesitter/nvim-treesitter-textobjects',
            'RRethy/nvim-treesitter-endwise',
            'RRethy/nvim-treesitter-textsubjects',
            'windwp/nvim-ts-autotag',
        },
        config = load_config('lang.treesitter'),
        event = { 'BufReadPre', 'BufNewFile' },
    },

}



for _, plugin in ipairs(plugins2) do
    table.insert(plugins, plugin)
end

local lsp_servers = {
    -- 'eslint',
    -- 'emmet_ls',
    -- 'html',
    -- 'cssls',
    -- 'jsonls',
    'lua_ls',
    'clangd',
    'tsserver',
}


local ts_parsers = {
    -- 'css',
    -- 'gitcommit',
    -- "tsx",
    -- 'html',
    -- "xml",
    'javascript',
    -- 'json',
    'lua',
    "c",
    -- "c_sharp",
    -- 'typescript',
}

return {
    plugins = plugins,
    lsp_servers = lsp_servers,
    ts_parsers = ts_parsers,
}
