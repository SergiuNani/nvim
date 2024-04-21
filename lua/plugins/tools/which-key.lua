local which_key = require('which-key')
local icons = require('lib.icons')
local setup = {
    plugins = {
        marks = true,
        registers = true,
        spelling = {
            enabled = true,
            suggestions = 30,
        },
        presets = {
            operators = true,
            motions = true,
            text_objects = true,
            windows = true,
            nav = true,
            z = true,
            g = true,
        },
    },
    key_labels = {
        ['<leader>'] = icons.ui.Rocket .. 'Space',
        ['<space>'] = icons.ui.Rocket .. 'Space',
    },
    icons = {
        breadcrumb = icons.ui.ArrowOpen,
        separator = icons.ui.Arrow,
        group = '',
    },
    triggers = 'auto',
    triggers_nowait = {
        -- marks
        '`',
        "'",
        'g`',
        "g'",
        -- registers
        '"',
        '<c-r>',
        -- spelling
        'z=',
    },
}

function TelescopeFindConfigFiles()
    require("telescope.builtin").find_files({ cwd = vim.fn.stdpath("config") })
end
local opts = {
    mode = 'n',
    prefix = '<leader>',
    buffer = nil,
    silent = true,
    noremap = true,
    nowait = true,
}
local mappings = {
    e = { '<cmd>NvimTreeToggle<cr>', icons.documents.OpenFolder .. 'Explorer' },
    q = { '<cmd>q<cr>', icons.ui.Close .. 'Quit' },
    Q = { '<cmd>qa!<cr>', icons.ui.Power .. 'Force Quit!' },
    w = { '<cmd>w<cr>', icons.ui.Save .. 'Save' },
    x = { '<cmd>x<cr>', icons.ui.Pencil .. 'Write and Quit' },
    f = {
        name = icons.ui.Telescope .. 'Find',
        --------------------==Find Files==--------------------
        b = { '<cmd>Telescope buffers<cr>', '[B]uffers' },
        f = { '<cmd>lua require("telescope").extensions.menufacture.find_files()<cr>', '[F]ind in Files' },
        G = { '<cmd>lua require("telescope").extensions.menufacture.git_files()<cr>', 'Find [G]it files' },
        r = { '<cmd>Telescope oldfiles<cr>', '[R]ecent Files' },
        --------------------==Find Words==--------------------
        c = { '<cmd>lua require("telescope").extensions.menufacture.grep_string()<cr>', 'Find Word under [c]ursor' },
        g = { '<cmd>lua require("telescope").extensions.menufacture.live_grep()<cr>', 'Find Grep Text' },
        s = { '<cmd>Telescope live_grep grep_open_files=true<cr>', 'Find in Open Files' },
        --------------------==Triks==--------------------
        l = { '<cmd>Telescope resume<cr>', '[R]esume Last Search' },
        n = { '<cmd>:lua TelescopeFindConfigFiles() <cr>', '[N]eovim config files' },
        v = { '<cmd>Telescope vim_options<cr>', '[V]im Options' },
        e = { '<cmd>Oil<cr>', 'Dir Editor' },--??
        L = { '<cmd>Telescope loclist<cr>', 'Location List' },--??
        q = { '<cmd>Telescope quickfix<cr>', '[Q]uickfix' },--??
    },
    g = {
        name = icons.git.Octoface .. 'Git',
        t = {
            name = 'Git Toggle',
        },
    },
    h = { name = icons.ui.Bookmark .. 'Harpoon' },
    r = {
        name = icons.diagnostics.Hint .. 'Refactor',
    },
    m = {
        name = icons.kind.Field .. 'Modes',
        h = { '<cmd>Hardtime toggle<cr>', 'Hardtime' },
        n = { '<cmd>Telescope notify<cr>', 'Notifications' },
        z = { '<cmd>ZenMode<cr>', 'ZenMode' },
    },
    p = {
        name = icons.ui.Package .. 'Packages',
        p = { '<cmd>Lazy<cr>', 'Plugins' },
        m = { '<cmd>Mason<cr>', 'Mason' },
        s = { '<cmd>Lazy sync<cr>', 'Sync' },
        u = { '<cmd>Lazy update<cr>', 'Update' },
    },
    c = {
        name = icons.ui.NeoVim .. 'Config',
        f = { '<cmd>lua vim.lsp.buf.format({async = true})<cr>', 'Format File' }, -->??
        i = { vim.show_pos, 'Inspect Position' },
        l = { '<cmd>:g/^\\s*$/d<cr>', 'Clean Empty Lines' },
        n = { '<cmd>set relativenumber!<cr>', 'Relative Numbers' },
        r = { '<cmd>Telescope reloader<cr>', 'Reload Module' },
        R = { '<cmd>ReloadConfig<cr>', 'Reload Configs' },
    },
    -- ------------------------------------------------------------
    -- b = {--??
    --     name = icons.ui.Bug .. 'Debug',
    --     b = { '<cmd>DapToggleBreakpoint<cr>', 'Breakpoint' },
    --     c = { '<cmd>DapContinue<cr>', 'Continue' },
    --     i = { '<cmd>DapStepInto<cr>', 'Into' },
    --     l = { "<cmd>lua require'dap'.run_last()<cr>", 'Last' },
    --     o = { '<cmd>DapStepOver<cr>', 'Over' },
    --     O = { '<cmd>DapStepOut<cr>', 'Out' },
    --     r = { '<cmd>DapToggleRepl<cr>', 'Repl' },
    --     R = { '<cmd>DapRestartFrame<cr>', 'Restart Frame' },
    --     t = { '<cmd>DapUIToggle<cr>', 'Debugger' },
    --     x = { '<cmd>DapTerminate<cr>', 'Exit' },
    -- },
    l = {
        name = icons.ui.Gear .. 'LSP',
    },

    t = {
        name = icons.ui.Terminal .. 'Terminal',
        n = { '<cmd>Sterm node<cr>', 'Node' },
    },
    s = {
        name = icons.ui.Windows .. 'Split',
        ['-'] = { '<C-w>v', 'Split Right'},
        d = { '<C-w>c', 'Close Window' },
        p = { '<C-w>p', 'Previous Window' },
        t = { '<cmd>tabnew<cr>', 'New Tab' },
        w = { '<cmd>w<cr>', 'Write' },
        x = { '<cmd>x<cr>', 'Write and Quit' },
    },
    y = {
        name = icons.ui.Clipboard .. 'Yank',
        f = { '<cmd>%y+<cr>', 'Copy Whole File' },
        p = { '<cmd>CRpath<cr>', 'Copy Relative Path' },
        P = { '<cmd>CApath<cr>', 'Copy Absolute Path' },
    },
}
local vopts = {
    mode = 'v',
    prefix = '<leader>',
    buffer = nil,
    silent = true,
    noremap = true,
    nowait = true,
}
local vmappings = {
    l = {
        name = icons.ui.Gear .. 'LSP',
        a = '<cmd><C-U>Lspsaga range_code_action<CR>',
    },
    q = { '<cmd>q<cr>', icons.ui.Close .. 'Quit' },
    Q = { '<cmd>qa!<cr>', icons.ui.Power .. 'Force Quit!' },
    x = { '<cmd>x<cr>', icons.ui.Pencil .. 'Write and Quit' },
}

local no_leader_opts = {
    mode = 'n',
    prefix = '',
    buffer = nil,
    silent = true,
    noremap = true,
    nowait = true,
}

local no_leader_mappings = {

    ['['] = {
        name = icons.ui.ArrowLeft .. 'Previous',
        b = { '<cmd>bprevious<cr>', 'Buffer' },
        B = { '<cmd>bfirst<cr>', 'First Buffer' },
        -- c = { '<cmd>Gitsigns prev_hunk<cr>', 'Previous Hunk' },
        e = { 'g;', 'Edit' },
        g = { '<cmd>Gitsigns prev_hunk<cr>', 'Git Hunk' },
        j = { '<C-o>', 'Jump' },
    },

    [']'] = {
        name = icons.ui.ArrowRight .. 'Next',
        b = { '<cmd>bnext<cr>', 'Buffer' },
        B = { '<cmd>blast<cr>', 'Buffer' },
        -- c = { '<cmd>Gitsigns next_hunk<cr>', 'Next Hunk' },
        e = { 'g,', 'Edit' },
        g = { '<cmd>Gitsigns next_hunk<cr>', 'Git Hunk' },
        j = { '<C-i>', 'Jump' },
    },
    ['#'] = { '<cmd>edit #<cr>', 'Alternate Buffer' },
    K = { '<cmd>Lspsaga hover_doc<cr>', 'LSP Hover' },
    U = { '<cmd>redo<cr>', 'Redo' },
}

which_key.setup(setup)
which_key.register(mappings, opts)
which_key.register(vmappings, vopts)
which_key.register(no_leader_mappings, no_leader_opts)
