local function augroup(name)
    return vim.api.nvim_create_augroup('Sergiu' .. name, { clear = true })
end

local function toggle_list()
    if vim.o.list then
        vim.o.list = false
        print("Hide hidden characters")
    else
        vim.o.list = true
        print("Show hidden characters")
    end
end

vim.api.nvim_create_user_command('ToggleList', toggle_list, {})
-- -- Strip trailing spaces before write
-- vim.api.nvim_create_autocmd({ 'BufWritePre' }, {
--     group = augroup('strip_space'),
--     pattern = { '*' },
--     callback = function()
--         vim.cmd([[ %s/\s\+$//e ]])
--     end,
-- })

-- -- Check if we need to reload the file when it changed
-- vim.api.nvim_create_autocmd({ 'FocusGained', 'TermClose', 'TermLeave' }, {
--     group = augroup('checktime'),
--     command = 'checktime',
-- })

-- Highlight on yank
vim.api.nvim_create_autocmd('TextYankPost', {
    group = augroup('highlight_yank'),
    callback = function()
        vim.highlight.on_yank()
    end,
})

-- -- resize splits if window got resized
-- vim.api.nvim_create_autocmd({ 'VimResized' }, {
--     group = augroup('resize_splits'),
--     callback = function()
--         vim.cmd('tabdo wincmd =')
--     end,
-- })

-- -- go to last loc when opening a buffer
-- vim.api.nvim_create_autocmd('BufReadPost', {
--     group = augroup('last_loc'),
--     callback = function()
--         local mark = vim.api.nvim_buf_get_mark(0, '"')
--         local lcount = vim.api.nvim_buf_line_count(0)
--         if mark[1] > 0 and mark[1] <= lcount then
--             pcall(vim.api.nvim_win_set_cursor, 0, mark)
--         end
--     end,
-- })



-- -- Auto create dir when saving a file, in case some intermediate directory does not exist
-- vim.api.nvim_create_autocmd({ 'BufWritePre' }, {
--     group = augroup('auto_create_dir'),
--     callback = function(event)
--         local file = vim.loop.fs_realpath(event.match) or event.match
--         vim.fn.mkdir(vim.fn.fnamemodify(file, ':p:h'), 'p')
--     end,
-- })
