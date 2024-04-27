local telescope = require('telescope')
local actions = require('telescope.actions')
local icons = require('lib.icons')

local function map(mode, lhs, rhs, opts)
    opts = opts or {}
    opts.silent = opts.silent ~= false
    vim.keymap.set(mode, lhs, rhs, opts)
end
local opts = { noremap = true, silent = true }
local function Teli_cmd(func_name, Ttype)
    --get_dropdown
    --get_ivy
    --get_cursor
    return string.format("<cmd>:lua require'telescope.builtin'.%s(require('telescope.themes').%s({}))<CR>",func_name,Ttype)
end


telescope.setup({
    defaults = {
        layout_config = {
            height = 0.8,
            width = 0.9,
            prompt_position = 'top',
            bottom_pane = {
                height = 0.5,
                preview_width = 0.6,
                preview_cutoff = 120,
            },
            center = {
                height = 0.4,
                preview_cutoff = 40,
            },
            cursor = {
                preview_cutoff = 40,
                preview_width = 0.6,
            },
            horizontal = {
                preview_width = 0.6,
                preview_cutoff = 120,
            },
            vertical = {
                preview_cutoff = 40,
            },
        },
        prompt_prefix = icons.ui.Telescope .. icons.ui.ChevronRight,
        selection_caret = icons.ui.Play,
        multi_icon = icons.ui.Check,
        -- path_display = { 'smart' },
        sorting_strategy = 'ascending',

        mappings = {
            i = {
                ['<A-h>'] = actions.select_horizontal,
                ['<A-v>'] = actions.select_vertical,
                ['<A-s>'] = actions.select_vertical,
                ['<C-t>'] = actions.select_tab,
                ['<M-e>'] = actions.preview_scrolling_up,
                ['<M-d>'] = actions.preview_scrolling_down,


                ['<esc>'] = actions.close,
                ['<C-n>'] = actions.cycle_history_next,
                ['<C-p>'] = actions.cycle_history_prev,

                ['<C-j>'] = actions.move_selection_next,
                ['<C-k>'] = actions.move_selection_previous,

                ['<C-c>'] = actions.close,

                ['<Down>'] = actions.move_selection_next,
                ['<Up>'] = actions.move_selection_previous,

                ['<CR>'] = actions.select_default,
                ['<PageUp>'] = actions.results_scrolling_up,
                ['<PageDown>'] = actions.results_scrolling_down,
                ['<Tab>'] = actions.toggle_selection + actions.move_selection_worse,
                ['<S-Tab>'] = actions.toggle_selection + actions.move_selection_better,
                ['<C-q>'] = actions.send_to_qflist + actions.open_qflist,
                ['<M-q>'] = actions.send_selected_to_qflist + actions.open_qflist,
                ['<C-l>'] = actions.complete_tag,
            },

            n = {
                ['<A-h>'] = actions.select_horizontal,
                ['<A-v>'] = actions.select_vertical,
                ['<A-s>'] = actions.select_vertical,
                ['<A-t>'] = actions.select_tab,
                ['<M-e>'] = actions.preview_scrolling_up,
                ['<M-d>'] = actions.preview_scrolling_down,

                ['q'] = actions.close,
                ['<esc>'] = actions.close,
                ['<CR>'] = actions.select_default,

                ['<Tab>'] = actions.toggle_selection + actions.move_selection_worse,
                ['<S-Tab>'] = actions.toggle_selection + actions.move_selection_better,
                ['<M-q>'] = actions.send_selected_to_qflist + actions.open_qflist,

                ['j'] = actions.move_selection_next,
                ['k'] = actions.move_selection_previous,
                ['H'] = actions.move_to_top,
                ['M'] = actions.move_to_middle,
                ['L'] = actions.move_to_bottom,

                ['<Down>'] = actions.move_selection_next,
                ['<Up>'] = actions.move_selection_previous,
                ['gg'] = actions.move_to_top,
                ['G'] = actions.move_to_bottom,

                ['<PageUp>'] = actions.results_scrolling_up,
                ['<PageDown>'] = actions.results_scrolling_down,

                ['?'] = actions.which_key,
            },
        },
    },
    extensions = {
        fzf = {
            fuzzy = true,
            override_generic_sorter = true,
            override_file_sorter = true,
            case_mode = 'smart_case',
        },
        menufacture = { mappings = { main_menu = { [{ 'i', 'n' }] = '<C-e>' } } },
    },

    map("n","<leader>f`",Teli_cmd("marks", "get_dropdown"),{ desc = "Lists of vim marks and their values" }),
    map("n","<leader>fk",Teli_cmd("commands", "get_dropdown"),{ desc = "Telescope Commands" }),
    map("n", "<leader>fm", Teli_cmd("keymaps", "get_dropdown"), { desc = "Show mappings" }),
    map("n", "<leader>fh", Teli_cmd("help_tags", "get_dropdown"), { desc = "Serch in HELP" }),
    map("n","<leader>fy",Teli_cmd("colorscheme", "get_dropdown"),{ desc = "Colorschemes" }),
    map("n", "<leader>fi", Teli_cmd("vim_options", "get_dropdown"), { desc = "VimOptions" }),
    map("n", "<leader>ft", Teli_cmd("builtin", "get_dropdown"), { desc = "[F]ind [Q]select Telescope" }),

    map("n", "<M-f>", "<cmd>Telescope resume<cr>", { desc = "Resume svim.keymap.setearch" }),
    map("n", "<C-p>", "<cmd>Telescope find_files<cr>", { desc = "Find Files" }),
    map("n", "<C-f>", "<cmd>Telescope current_buffer_fuzzy_find<cr>", { desc = "Search in current buffer" })

})

require('telescope').load_extension('fzf')
require('telescope').load_extension('menufacture')
require('telescope').load_extension('harpoon')
require('telescope').load_extension('notify')
-- require('telescope').load_extension('bookmarks')
