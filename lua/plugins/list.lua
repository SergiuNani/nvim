local function load_config(package)
    return function()
        require('plugins.' .. package)
    end
end

local plugins = {
    ---- ======================== First Priority  =======================
    {
        "LintaoAmons/bookmarks.nvim",
        -- "tomasky/bookmarks.nvim",
  -- 'crusj/bookmarks.nvim',
        dependencies = {
            {"stevearc/dressing.nvim"} 
        },
        -- branch = 'main',
        config = load_config('ui.bookmarks'),
        event = { 'BufReadPre', 'BufNewFile' },
    },
    {
        "folke/tokyonight.nvim",
        dependencies={
            'navarasu/onedark.nvim',
            -- "bluz71/vim-nightfly-guicolors",--ehh
            -- 'olimorris/onedarkpro.nvim',
            -- "rebelot/kanagawa.nvim", --5/10
            -- "ribru17/bamboo.nvim", --6/10
            -- "rose-pine/neovim", --3/10
            -- "ellisonleao/gruvbox.nvim", --7/10
            -- "marko-cerovac/material.nvim", --2/10
        },
        config = load_config('ui.colorscheme'),
        lazy = false,
        priority = 1000,
    },
    {
        'stevearc/oil.nvim',
        opts = {},
        -- Optional dependencies
        dependencies = { "nvim-tree/nvim-web-devicons" },
        config = load_config('ui.oil'),
        event = {'VimEnter' },
    },

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
        priority=1000,
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

    -- ======================== Secondary Priority  =======================
    {
        'windwp/nvim-autopairs',
        config = load_config('lang.autopairs'),
        event = 'InsertEnter',
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
        config = load_config('ui.auto-session'),
        "rmagatti/auto-session",
        event = {'VimEnter' },
    },
    {
        '2kabhishek/termim.nvim', -- For lazyGit
        cmd = { 'Fterm', 'FTerm', 'Sterm', 'STerm', 'Vterm', 'VTerm' },
    },
    {
        'lewis6991/gitsigns.nvim',
        cmd = 'Gitsigns',
        config = load_config('tools.gitsigns'),
        event = {'VimEnter' },
    },
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
            { "j-hui/fidget.nvim", opts = {} }, -- Right bottom corner when enter it shows the %  of LSP
            { 'hrsh7th/cmp-nvim-lsp',opts={}},
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


    --
    {
        "https://github.com/ThePrimeagen/vim-be-good",
        event = 'UIEnter',
    },
    --  Tresitter ----------------
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
    -- {
    --     'folke/zen-mode.nvim',
    --     config = load_config('ui.zen-mode'),
    -- },
    { -- Search text and if color => show color
        "NvChad/nvim-colorizer.lua",
        event = { "BufReadPre", "BufNewFile" },
        config = true,
    },
    {
        'nvim-lualine/lualine.nvim',
        config = load_config('ui.lualine'),
        event = { 'BufReadPre', 'BufNewFile' },
    },
    {
        'HiPhish/rainbow-delimiters.nvim',
        config = load_config('ui.rainbow'),
        event = { 'BufReadPre', 'BufNewFile' },
    },
    {
        'rcarriga/nvim-notify',
        config = load_config('ui.notify'),
        event = 'VeryLazy',
        cmd = 'Notifications',
    },
    {
        'stevearc/dressing.nvim',
        --Basically wraps UI around renaming/adding files in nvim-tree
        config = load_config('ui.dressing'),
        event = { 'BufReadPre', 'BufNewFile' },
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
    -- { --???? to investigate
    --     "mg979/vim-visual-multi",
    --     config = load_config('tools.VimVisualMulti'),

    -- },
    -- {
    --     'echasnovski/mini.surround',
    --     version = '*',
    --     config = load_config('lang.surround'),
    --     event = { 'BufReadPre', 'BufNewFile' },
    -- },
    -- {
    --     'echasnovski/mini.ai',
    --     version = '*',
    --     config = load_config('lang.ai'),
    --     event = { 'BufReadPre', 'BufNewFile' },
    -- },

    -- {
    --     'm4xshen/hardtime.nvim',
    --     dependencies = { 'MunifTanjim/nui.nvim', 'nvim-lua/plenary.nvim' },
    --     config = function()
    --         require('hardtime').setup({ enabled = true })
    --     end,
    --     cmd = 'Hardtime',
    -- },



    -- {
    --     'zbirenbaum/copilot.lua',
    --     dependencies = {
    --         'zbirenbaum/copilot-cmp',
    --     },
    --     config = load_config('lang.copilot'),
    --     event = 'InsertEnter',
    -- },

}

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
