    require("hlchunk").setup({
      chunk = {
        -- The one you want
        enable = true,
        -- notify = true,
        use_treesitter = true,
        chars = {
          horizontal_line = "─",
          vertical_line = "│",
          left_top = "╭",
          left_bottom = "╰",
          right_arrow = ">",
        },
        style = {
          { fg = "#806d9c" },
          { fg = "#c21f30" }, -- this fg is used to highlight wrong chunk
        },
        textobject = "",
        max_file_size = 1024 * 1024,
        error_sign = true,
      },

      indent = {
        enable = false,
        use_treesitter = false,
        chars = {
          "│",
          -- "┊",
        },
        -- style = {
        --   { fg = vim.fn.synIDattr(vim.fn.synIDtrans(vim.fn.hlID("Whitespace")), "fg", "gui") },
        -- },
      },

      line_num = {
        enable = false,
      },

      blank = {
        enable = false,
      },
    })
