 -- "LintaoAmons/bookmarks.nvim",

require("bookmarks").setup({})
      -- json_db_path = vim.fs.normalize(vim.fn.stdpath("config") .. "/bookmarks.db.json"),
vim.keymap.set({ "n", "v" }, "mm", "<cmd>BookmarksMark<cr>", { desc = "Mark current line into active BookmarkList." })
vim.keymap.set({ "n", "v" }, "ml", "<cmd>BookmarksGoto<cr>", { desc = "Go to bookmark at current active BookmarkList" })
vim.keymap.set({ "n", "v" }, "ma", "<cmd>BookmarksCommands<cr>", { desc = "Find and trigger a bookmark command." })
vim.keymap.set({ "n", "v" }, "mg", "<cmd>BookmarksGotoRecent<cr>", { desc = "Go to latest visited/created Bookmark" })
vim.keymap.set({ "n", "v" }, "mf", "<cmd>BookmarksSetActiveList<cr>", { desc = "Go to latest visited/created Bookmark" })
vim.keymap.set({ "n", "v" }, "mn", "<cmd>BookmarksAddList<cr>", { desc = "Go to latest visited/created Bookmark" })

