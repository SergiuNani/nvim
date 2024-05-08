local handler = function(virtText, lnum, endLnum, width, truncate)
    local newVirtText = {}
    local suffix = (" 󰁂 %d "):format(endLnum - lnum)
    local sufWidth = vim.fn.strdisplaywidth(suffix)
    local targetWidth = width - sufWidth
    local curWidth = 0
    for _, chunk in ipairs(virtText) do
        local chunkText = chunk[1]
        local chunkWidth = vim.fn.strdisplaywidth(chunkText)
        if targetWidth > curWidth + chunkWidth then
            table.insert(newVirtText, chunk)
        else
            chunkText = truncate(chunkText, targetWidth - curWidth)
            local hlGroup = chunk[2]
            table.insert(newVirtText, { chunkText, hlGroup })
            chunkWidth = vim.fn.strdisplaywidth(chunkText)
            -- str width returned from truncate() may less than 2nd argument, need padding
            if curWidth + chunkWidth < targetWidth then
                suffix = suffix .. (" "):rep(targetWidth - curWidth - chunkWidth)
            end
            break
        end
        curWidth = curWidth + chunkWidth
    end
    table.insert(newVirtText, { suffix, "MoreMsg" })
    return newVirtText
end

vim.o.foldcolumn = "0" -- '0' is not bad
vim.o.foldlevel = 99   -- Using ufo provider need a large value, feel free to decrease the value
vim.o.foldlevelstart = 99
--vim.o.foldenable = true

require("ufo").setup({
    open_fold_hl_timeout = 150,
    fold_virt_text_handler = handler,
    provider_selector = function(bufnr, filetype, buftype)
        return { "treesitter", "indent" }
    end,
})
vim.keymap.set("n", "zR", require("ufo").openAllFolds)
vim.keymap.set("n", "zM", require("ufo").closeAllFolds)
vim.keymap.set("n", "zr", require("ufo").openFoldsExceptKinds)
vim.keymap.set("n", "zm", require("ufo").closeFoldsWith) -- closeAllFolds == closeFoldsWith(0)
vim.api.nvim_set_keymap("n", "<leader>z", [[:let &l:fdl=indent('.')/&sw<CR>]], { silent = true })

vim.keymap.set("n", "zp", function()
    local winid = require("ufo").peekFoldedLinesUnderCursor()
    if not winid then
        -- choose one of coc.nvim and nvim lsp
        vim.fn.CocActionAsync("definitionHover") -- coc.nvim
        vim.lsp.buf.hover()
    end
end)
-- Using ufo provider need remap `zR` and `zM`. If Neovim is 0.6.1, remap yourself

-- function CloseFoldOpens(opens_level)
--     local lineno = 2
--     local last = vim.fn.line("$")
--     while lineno < last do
--         if vim.fn.foldclosed(lineno) ~= -1 then
--             lineno = vim.fn.foldclosedend(lineno) + 1
--         elseif
--             vim.fn.foldlevel(lineno) > vim.fn.foldlevel(lineno - 1)
--             and vim.fn.foldlevel(lineno) == opens_level
--         then
--             vim.api.nvim_command(tostring(lineno) .. "foldclose")
--             lineno = vim.fn.foldclosedend(lineno) + 1
--         else
--             lineno = lineno + 1
--         end
--     end
-- end

-- vim.api.nvim_set_keymap("n", "z1", ":%foldclose<CR>", { silent = true })
-- vim.api.nvim_set_keymap("n", "z2", ":lua CloseFoldOpens(2)<CR>", { silent = true })
-- vim.api.nvim_set_keymap("n", "z3", ":lua CloseFoldOpens(3)<CR>", { silent = true })
-- vim.api.nvim_set_keymap("n", "z4", ":lua CloseFoldOpens(4)<CR>", { silent = true })
-- vim.api.nvim_set_keymap("n", "z5", ":lua CloseFoldOpens(5)<CR>", { silent = true })




vim.api.nvim_set_keymap("n", "z0", ":set foldlevel=0 <CR>", { silent = true })
vim.api.nvim_set_keymap("n", "z1", ":set foldlevel=1<CR>", { silent = true })
vim.api.nvim_set_keymap("n", "z2", ":set foldlevel=2<CR>", { silent = true })
vim.api.nvim_set_keymap("n", "z3", ":set foldlevel=3<CR>", { silent = true })
vim.api.nvim_set_keymap("n", "z4", ":set foldlevel=4<CR>", { silent = true })
vim.api.nvim_set_keymap("n", "z5", ":set foldlevel=5<CR>", { silent = true })
vim.api.nvim_set_keymap("n", "z6", ":set foldlevel=6<CR>", { silent = true })
vim.api.nvim_set_keymap("n", "z7", ":set foldlevel=7<CR>", { silent = true })
vim.api.nvim_set_keymap("n", "z8", ":set foldlevel=8<CR>", { silent = true })
vim.api.nvim_set_keymap("n", "z9", ":set foldlevel=9<CR>", { silent = true })
