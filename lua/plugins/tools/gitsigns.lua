local gitsigns = require('gitsigns')

gitsigns.setup({
    signs = {
        add = {
            hl = 'GitSignsAdd',
            text = '+',
            numhl = 'GitSignsAddNr',
            linehl = 'GitSignsAddLn',
        },
        change = {
            hl = 'GitSignsChange',
            text = '│',
            numhl = 'GitSignsChangeNr',
            linehl = 'GitSignsChangeLn',
        },
        delete = {
            hl = 'GitSignsDelete',
            text = '_',
            numhl = 'GitSignsDeleteNr',
            linehl = 'GitSignsDeleteLn',
        },
        topdelete = {
            hl = 'GitSignsDelete',
            text = '‾',
            numhl = 'GitSignsDeleteNr',
            linehl = 'GitSignsDeleteLn',
        },
        changedelete = {
            hl = 'GitSignsChange',
            text = '~',
            numhl = 'GitSignsChangeNr',
            linehl = 'GitSignsChangeLn',
        },
    },
    signcolumn = true,
    numhl = true,
    linehl = false,
    word_diff = false,
    watch_gitdir = { interval = 1000, follow_files = true },
    attach_to_untracked = true,
    current_line_blame = false,
    current_line_blame_opts = {
        virt_text = true,
        virt_text_pos = 'eol',
        delay = 0,
        ignore_whitespace = false,
    },
    current_line_blame_formatter = '<author>, <author_time:%Y-%m-%d> - <summary>',
    sign_priority = 6,
    update_debounce = 100,
    status_formatter = nil,
    max_file_length = 40000,
    preview_config = { border = 'single', style = 'minimal', relative = 'cursor', row = 0, col = 1 },
    yadm = { enable = false },
    on_attach = function(bufnr)
        local function map(mode, l, r, opts)
            opts = opts or {}
            opts.buffer = bufnr
            vim.keymap.set(mode, l, r, opts)
        end


        map({ 'v' }, '<leader>ga', ':Gitsigns stage_hunk<CR>', { desc = 'Stage Hunk' })
        map({ 'v' }, '<leader>gr', ':Gitsigns reset_hunk<CR>', { desc = 'Reset Hunk' })

        map('n', '<leader>gg', '<cmd>Fterm lazygit<cr>', { desc = 'Lazygit' })
        map('n', ']c', '<cmd>Gitsigns next_hunk<cr>', { desc = 'Next Hunk' })
        map('n', '[c', '<cmd>Gitsigns prev_hunk<cr>', { desc = 'Previous Hunk' })
        -- map('n', '<leader>gd', '<cmd>Gitsigns diffthis HEAD<cr>', { desc = 'Diff on current buffer' })

        map('n', '<leader>gp', '<cmd>Gitsigns preview_hunk<cr>', { desc = 'Preview Hunk' })
        map('n', '<leader>gs', '<cmd>Telescope git_status<cr>', { desc = 'Changed files' })

        map('n', '<leader>gb', '<cmd>Gitsigns blame_line<cr>', { desc = 'Blame' })

        -- //Toggle options
        map('n', '<leader>gtb', '<cmd>Gitsigns toggle_current_line_blame<cr>', { desc = 'Toggle Blame' })
        map('n', '<leader>gtd', '<cmd>Gitsigns toggle_deleted<cr>', { desc = 'Toggle Deleted lines' })
        map('n', '<leader>gtl', '<cmd>Gitsigns toggle_linehl<cr>', { desc = 'Toggle Line HL' })
    end,
})
