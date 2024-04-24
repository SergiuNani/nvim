    require("hlchunk").setup({
      chunk = {
        -- The one you want
        enable = true,
        notify = false, --important, otherwise ull get a message for all the files you enter in
        use_treesitter = true,
      },

      indent = {
        enable = true,
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
