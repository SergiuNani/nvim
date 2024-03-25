local function load_config(package)
    return function()
        require('plugins.' .. package)
    end
end

local plugins = {
    ---------------- UI ----------------
    {
        'navarasu/onedark.nvim',
        config = load_config('ui.onedark'),
        lazy = false,
        priority = 1000,
    },
    {
        'nvim-lualine/lualine.nvim',
        config = load_config('ui.lualine'),
        event = { 'BufReadPre', 'BufNewFile' },
    },
    {
        'lukas-reineke/indent-blankline.nvim',
        config = load_config('ui.indentline'),
        main = 'ibl',
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
        'nvimdev/dashboard-nvim',
        config = load_config('ui.dashboard'),
        -- Only load when no arguments
        event = function()
            if vim.fn.argc() == 0 then
                return 'VimEnter'
            end
        end,
        cmd = 'Dashboard',
    },
    {
        'folke/zen-mode.nvim',
        dependencies = {
            'folke/twilight.nvim',
            config = load_config('ui.twilight'),
        },
        config = load_config('ui.zen-mode'),
        cmd = { 'ZenMode' ,'Twilight' },
    },

    --  ---------------- Language ----------------
    {
        'windwp/nvim-autopairs',
        config = load_config('lang.autopairs'),
        event = 'InsertEnter',
    },
    {
        'echasnovski/mini.comment',
        version = '*',
        dependencies = 'JoosepAlviste/nvim-ts-context-commentstring',
        config = load_config('lang.comment'),
        event = { 'BufReadPre', 'BufNewFile' },
    },

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

    -- ---------------- Tresitter ----------------
    {
        'nvim-treesitter/nvim-treesitter',
        build = ':TSUpdate',
        dependencies = {
            'nvim-treesitter/nvim-treesitter-refactor',
            'nvim-treesitter/nvim-treesitter-textobjects',
            'RRethy/nvim-treesitter-endwise',
            'RRethy/nvim-treesitter-textsubjects',
            'windwp/nvim-ts-autotag',
        },
        config = load_config('lang.treesitter'),
        event = { 'BufReadPre', 'BufNewFile' },
    },
    {
        'ckolkey/ts-node-action',
        dependencies = { 'nvim-treesitter' },
    },
    --  ----------------LSP ----------------
    {
        'neovim/nvim-lspconfig',
        dependencies = {
            { "antosha417/nvim-lsp-file-operations", config = true },
            { "j-hui/fidget.nvim", opts = {} },
            { 'hrsh7th/cmp-nvim-lsp',opts={}},
        },
        config = load_config('lang.lspconfig'),
        event = { 'BufReadPre', 'BufNewFile' },
    },
    {
        'folke/neodev.nvim',
        ft = { 'lua', 'vim' },
        config = load_config('lang.neodev'),
    },
    {
        'nvimdev/lspsaga.nvim',
        config = load_config('lang.lspsaga'),
        event = 'LspAttach',
    },
    {
        'Maan2003/lsp_lines.nvim',
        config = load_config('lang.lsp-lines'),
        event = 'LspAttach',
    },
    {
        'williamboman/mason.nvim',
        dependencies = {
            "williamboman/mason-lspconfig.nvim",
            "WhoIsSethDaniel/mason-tool-installer.nvim",
        },
        config = load_config('lang.mason'),
        cmd = 'Mason',
    },

    -- ---------------- Completion ----------------
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
    -- {
    --     'zbirenbaum/copilot.lua',
    --     dependencies = {
    --         'zbirenbaum/copilot-cmp',
    --     },
    --     config = load_config('lang.copilot'),
    --     event = 'InsertEnter',
    -- },

    --  ---------------- Tools ----------------
    {
        'nvim-tree/nvim-tree.lua',
        dependencies = {
            'nvim-tree/nvim-web-devicons',
        },
        config = load_config('tools.nvim-tree'),
        cmd = 'NvimTreeToggle',
    },
    {
        'windwp/nvim-spectre',
        config = load_config('tools.spectre'),
        cmd = 'Spectre',
    },
    -- { --???? to investigate
    --     "mg979/vim-visual-multi",
    --     config = load_config('tools.VimVisualMulti'),

    -- },
    {
        "NvChad/nvim-colorizer.lua",
        event = { "BufReadPre", "BufNewFile" },
        config = true,
    },
    {
        'folke/flash.nvim',
        config = load_config('tools.flash'),
        keys = {
            {
                's',
                mode = { 'n', 'x', 'o' },
                function()
                    require('flash').jump()
                end,
                desc = 'Flash',
            },
            {
                'S',
                mode = { 'n', 'x', 'o' },
                function()
                    require('flash').treesitter()
                end,
                desc = 'Flash Treesitter',
            },
            {
                'r',
                mode = 'o',
                function()
                    require('flash').remote()
                end,
                desc = 'Remote Flash',
            },
            {
                'R',
                mode = { 'o', 'x' },
                function()
                    require('flash').treesitter_search()
                end,
                desc = 'Treesitter Search',
            },
            {
                '<c-s>',
                mode = { 'c' },
                function()
                    require('flash').toggle()
                end,
                desc = 'Toggle Flash Search',
            },
        },
    },
    {
        'm4xshen/hardtime.nvim',
        dependencies = { 'MunifTanjim/nui.nvim', 'nvim-lua/plenary.nvim' },
        config = function()
            require('hardtime').setup({ enabled = true })
        end,
        cmd = 'Hardtime',
    },
    {
        'folke/which-key.nvim',
        config = load_config('tools.which-key'),
        event = 'VeryLazy',
    },
    {
        '2kabhishek/termim.nvim',
        cmd = { 'Fterm', 'FTerm', 'Sterm', 'STerm', 'Vterm', 'VTerm' },
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
            'nvim-telescope/telescope-symbols.nvim',
            'molecule-man/telescope-menufacture',
            'debugloop/telescope-undo.nvim',
        },
        config = load_config('tools.telescope'),
        cmd = 'Telescope',
    },
    {
        'ThePrimeagen/harpoon',
        branch = 'harpoon2',
        config = load_config('tools.harpoon'),
        priority=1000,
        event = { 'BufReadPre', 'BufNewFile' },
    },

    -- -- Git
    {
        'lewis6991/gitsigns.nvim',
        config = load_config('tools.gitsigns'),
        cmd = 'Gitsigns',
        event = { 'BufReadPre', 'BufNewFile' },
    },
}

local lsp_servers = {
    'eslint',
    'emmet_ls',
    'html',
    'cssls',
    'jsonls',
    'lua_ls',
    'tsserver',
}

-- local null_ls_sources = {
--     'shellcheck', -- bash lint
-- }

local ts_parsers = {
    'css',
    'gitcommit',
    "javascript",
    "tsx",
    'html',
    "xml",
    'javascript',
    'json',
    'lua',
    "c",
    "c_sharp",
    'typescript',
}

return {
    plugins = plugins,
    lsp_servers = lsp_servers,
    null_ls_sources = null_ls_sources,
    ts_parsers = ts_parsers,
}
