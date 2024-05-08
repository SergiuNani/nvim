local todo_comments = require("todo-comments")

-- set keymaps
local keymap = vim.keymap -- for conciseness

keymap.set("n", "]t", function()
    todo_comments.jump_next()
end, { desc = "Next todo comment" })

keymap.set("n", "[t", function()
    todo_comments.jump_prev()
end, { desc = "Previous todo comment" })

todo_comments.setup({


    keywords = {
        FIX = {
            icon = " ", -- icon used for the sign, and in search results
            color = "error", -- can be a hex color, or a named color (see below)
            alt = { "FIXME", "BUG", "FIXIT", "ISSUE" }, -- a set of other keywords that all map to this FIX keywords
            -- signs = false, -- configure signs for some keywords individually
        },
        TODO = { icon = " ", color = "info" },
        HACK = { icon = " ", color = "warning" },
        WARN = { icon = " ", color = "warning", alt = { "WARNING" } },
        PERF = { icon = " ", alt = { "OPTIM", "PERFORMANCE", "OPTIMIZE" } },
        NOTE = { icon = " ", color = "hint", alt = { "INFO" } },
        TEST = { icon = "⏲ ", color = "test", alt = { "TESTING", "PASSED", "FAILED" } },
    },
})
