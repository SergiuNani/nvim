local auto_session = require("auto-session")
auto_session.setup({
    auto_restore_enabled = true,
})

local keymap = vim.keymap

keymap.set("n", "<leader>mr", "<cmd>SessionRestore<CR>", { desc = "Restore session for cwd" }) -- restore last workspace session for current directory
keymap.set("n", "<leader>ms", "<cmd>SessionSave<CR>", { desc = "Save session for auto session root dir" }) -- save workspace session for current working directory
keymap.set("n", "<leader>mt", "<cmd>Autosession search<CR>", { desc = "Search Sessions" }) -- save workspace session for current working directory
keymap.set("n", "<leader>md", "<cmd>Autosession delete<CR>", { desc = "Delete sessions" }) -- save workspace session for current working directory
