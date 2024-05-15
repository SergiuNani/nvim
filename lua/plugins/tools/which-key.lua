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
    f = {
        name = icons.ui.Telescope .. 'Find',
        -- --------------------==Find Words==--------------------
        -- q = { '<cmd>lua require("telescope").extensions.menufacture.grep_string()<cr>', 'Find Word under [c]ursor' },
        -- w = { '<cmd>lua require("telescope").extensions.menufacture.live_grep()<cr>', 'Find Grep Text' },
        --------------------==Triks==--------------------
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
        name = icons.ui.Package .. 'Project',
        l = { '<cmd>Lazy<cr>', 'Plugins' },
        s = { '<cmd>Sterm powershell<cr>', 'Powershell terminal' },
    },

    l = {
        name = icons.ui.Gear .. 'LSP',
    },

    s = {
        name = icons.ui.Windows .. 'Split',
    },
    y = {
        name = icons.ui.Clipboard .. 'Yank',
    },
}

which_key.setup(setup)
which_key.register(mappings, opts)
