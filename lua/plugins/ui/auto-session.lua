local auto_session = require("auto-session")
auto_session.setup({
    auto_restore_enabled = true,
})

local keymap = vim.keymap

keymap.set("n", "<leader>mt", "<cmd>Autosession search<CR>", { desc = "Search Sessions Telescope" })
keymap.set("n", "<leader>md", "<cmd>Autosession delete<CR>", { desc = "Delete sessions" })

keymap.set("n", "<leader>mr",
    function()
        vim.notify("Session Restored")
        vim.cmd("SessionRestore")
    end
    , { desc = "Restore session for cwd" })

keymap.set("n", "<leader>ms",
    function()
        vim.notify("Session Saved")
        vim.cmd("SessionSave")
    end
    , { desc = "Save session for auto session root dir" })

