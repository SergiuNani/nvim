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
    q = { '<cmd>x<cr>', icons.ui.Close .. 'Quit' },
    Q = { '<cmd>qa!<cr>', icons.ui.Power .. 'Force Quit!' },
    w = { '<cmd>w<cr>', icons.ui.Save .. 'Save' },
    x = { '<cmd>q<cr>', icons.ui.Pencil .. 'Write and Quit' },
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
        L = { '<cmd>Telescope loclist<cr>', 'Location List' }, --??
        q = { '<cmd>Telescope quickfix<cr>', '[Q]uickfix' },   --??
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
        s = { '<cmd>Sterm powershell<cr>', 'Node' },
    },

    l = {
        name = icons.ui.Gear .. 'LSP',
    },

    s = {
        name = icons.ui.Windows .. 'Split',
    },
    y = {
        name = icons.ui.Clipboard .. 'Yank',
        f = { '<cmd>%y+<cr>', 'Copy Whole File' },
        P = { '<cmd>CRpath<cr>', 'Copy Relative Path' },
        p = { '<cmd>CApath<cr>', 'Copy Absolute Path' },
    },
}

which_key.setup(setup)
which_key.register(mappings, opts)
