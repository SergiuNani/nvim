local auto_session = require("auto-session")
auto_session.setup({
    auto_restore_enabled = true,
})

local keymap = vim.keymap

keymap.set("n", "<leader>mf", "<cmd>Autosession search<CR>", { desc = "[F]ind Sessions in Telescope" })
keymap.set("n", "<leader>mx", "<cmd>Autosession delete<CR>", { desc = "Delete sessions" })
keymap.set("n", "<leader>mr", function()
    vim.notify("Session [R]estored")
    vim.cmd("SessionRestore")
end, { desc = "Session Restored" })
keymap.set("n", "<leader>ma", function()
    vim.notify("Session Added")
    vim.cmd("SessionSave")
end, { desc = "Session [A]dded" })
