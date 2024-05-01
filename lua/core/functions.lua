-- Reload neovim config
vim.api.nvim_create_user_command('ReloadConfig', function()
    for name, _ in pairs(package.loaded) do
        if name:match('^plugins') then
            package.loaded[name] = nil
        end
    end

    dofile(vim.env.MYVIMRC)
    vim.notify('Nvim configuration reloaded!', vim.log.levels.INFO)
end, {})

-- Copy relative path
vim.api.nvim_create_user_command('CRpath', function()
    local path = vim.fn.expand('%')
    vim.fn.setreg('+', path)
    vim.notify('Copied "' .. path .. '" to the clipboard!')
end, {})

-- Copy absolute path
vim.api.nvim_create_user_command('CApath', function()
    local path = vim.fn.expand('%:p')
    vim.fn.setreg('+', path)
    vim.notify('Copied "' .. path .. '" to the clipboard!')
end, {})

-- Switch to git root or file parent dir
vim.api.nvim_create_user_command('RootDir', function()
    local root = require('lib.util').get_root_dir()

    if root == '' then
        return
    end
    vim.cmd('lcd ' .. root)
end, {})

vim.api.nvim_create_autocmd('LspAttach', {
    -- This fucntion looks if the name of the file is vars_legacy and disables the LSP
    callback = function(lang)
        local buf_name = vim.fn.expand("%")
        if string.find(buf_name, "vars_legacy") then
            vim.schedule(function()
                vim.notify('Max_Performance. TreeSitter and LSP disabled!', vim.log.levels.INFO)
                vim.diagnostic.disable()
                vim.cmd(":LspStop")
            end)
        end
    end,
})
