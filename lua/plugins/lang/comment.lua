local comment = require('mini.comment')

require('ts_context_commentstring').setup({
    enable_autocmd = false,
    -- languages = { typescript = '// %s' },
})

comment.setup({
    options = {
        custom_commentstring = function()
            return require('ts_context_commentstring.internal').calculate_commentstring() or vim.bo.commentstring
        end,
        ignore_blank_line = true,
        start_of_line = false,
        pad_comment_parts = true,
    },

    mappings = {
        -- Toggle comment (like `gcip` - comment inner paragraph) for both
        comment = '<C-_>',
        comment_line = '<C-_>',
        comment_visual = '<C-_>',
        -- Define 'comment' textobject (like `dgc` - delete whole comment block)
        textobject = '<C-_>',
    },
})
