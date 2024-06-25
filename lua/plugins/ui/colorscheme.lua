require('onedark').setup {
    style = 'warmer',
    --warmer, dark, darker
}
require("catppuccin").setup({})
require("gruvbox").setup({})
require("ayu").setup({})
-- require("vim-colors-xcode").setup({})
-- require('onedark').load()

local bg = "#011628"
local bg_dark = "#011423"
local bg_highlight = "#143652"
local bg_search = "#0A64AC"
local bg_visual = "#275378"
local fg = "#CBE0F0"
local fg_dark = "#B4D0E9"
local fg_gutter = "#627E97"
local border = "#547998"

require("tokyonight").setup({
    style = "night",
    on_colors = function(colors)
        colors.bg = bg
        colors.bg_dark = bg_dark
        colors.bg_float = bg_dark
        colors.bg_highlight = bg_highlight
        colors.bg_popup = bg_dark
        colors.bg_search = bg_search
        colors.bg_sidebar = bg_dark
        colors.bg_statusline = bg_dark
        colors.bg_visual = bg_visual
        colors.border = border
        colors.fg = fg
        colors.fg_dark = fg_dark
        colors.fg_float = fg
        colors.fg_gutter = fg_gutter
        colors.fg_sidebar = fg_dark
    end
})

require("tokyonight").setup({})
-- vim.cmd([[colorscheme tokyonight]])
-- vim.cmd([[colorscheme onedark-vivid]]) -- 7/10 a lot of red ehh
-- vim.cmd([[colorscheme nightfly]]) --ehhh
-- vim.cmd([[colorscheme tokyonight]]) --ehhh
-- vim.cmd([[colorscheme kanagawa]]) --5/10
-- vim.cmd([[colorscheme bamboo]]) --6/10
-- vim.cmd([[colorscheme rose-pine]]) --6/10
-- vim.cmd([[colorscheme gruvbox]]) --6/10
vim.cmd([[colorscheme ayu-mirage]]) --6/10
-- vim.cmd([[colorscheme xcodedarkhc]]) --6/10



local function map(mode, lhs, rhs, opts)
    opts = opts or {}
    opts.silent = opts.silent ~= false
    vim.keymap.set(mode, lhs, rhs, opts)
end
local opts = { noremap = true, silent = true }


map("n", "<Leader>1", [[:colorscheme ayu-mirage<CR>]], { desc = "Colorscheme 1" })
map("n", "<Leader>2", [[:colorscheme xcodedarkhc <CR>]], { desc = "Colorscheme 2" })
map("n", "<Leader>3", [[:colorscheme tokyonight-moon<CR>]], { desc = "Colorscheme 3" })

map("n", "<Leader>4", [[:colorscheme gruvbox<CR>]], { desc = "Colorscheme 4" })
map("n", "<Leader>5", [[:colorscheme onedark<CR>]], { desc = "Colorscheme 5" })
map("n", "<Leader>6", [[:colorscheme ayu-dark<CR>]], { desc = "Colorscheme 6" })

map("n", "<Leader>7", [[:colorscheme xcodelighthc<CR>]], { desc = "Colorscheme 7" })
map("n", "<Leader>8", [[:colorscheme tokyonight-day<CR>]], { desc = "Colorscheme 8" })
map("n", "<Leader>9", [[:colorscheme ayu-light<CR>]], { desc = "Colorscheme 9" })


-- //Maybe  rose-moon
-- //Maybe  kanagawa-wave
