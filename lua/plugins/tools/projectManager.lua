local projectManager = require('projectmgr')
projectManager.setup({

    autogit = {
        enabled = false,
        command = "git pull --ff-only",
    },
    reopen = true,
    session = { enabled = false, file = "Session.vim" },
    shada = { enabled = false, file = "main.shada" },
    scripts = {
        enabled = true,
        file_startup = "startup.sh",
        file_shutdown = "shutdown.sh",
    },

})
vim.api.nvim_set_keymap("n", "<C-p>", ":ProjectMgr<CR>", {})
