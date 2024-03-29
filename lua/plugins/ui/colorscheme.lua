
require("tokyonight").setup(require("tokyonight").setup({
  on_highlights = function(hl, c)
    local prompt = "#2d3149"
    hl.TelescopeNormal = {
      bg = c.bg_dark,
      fg = c.fg_dark,
    }
    hl.TelescopeBorder = {
      bg = c.bg_dark,
      fg = c.bg_dark,
    }
    hl.TelescopePromptNormal = {
      bg = prompt,
    }
    hl.TelescopePromptBorder = {
      bg = prompt,
      fg = prompt,
    }
    hl.TelescopePromptTitle = {
      bg = prompt,
      fg = prompt,
    }
    hl.TelescopePreviewTitle = {
      bg = c.bg_dark,
      fg = c.bg_dark,
    }
    hl.TelescopeResultsTitle = {
      bg = c.bg_dark,
      fg = c.bg_dark,
    }
  end,
}))


-- vim.cmd([[colorscheme onedark]])
-- vim.cmd([[colorscheme onedark-vivid]]) -- 7/10 a lot of red ehh
-- vim.cmd([[colorscheme nightfly]]) --ehhh
-- vim.cmd([[colorscheme tokyonight]]) --ehhh
-- vim.cmd([[colorscheme kanagawa]]) --5/10
-- vim.cmd([[colorscheme bamboo]]) --6/10
-- vim.cmd([[colorscheme rose-pine]]) --6/10
-- vim.cmd([[colorscheme gruvbox]]) --6/10
