require("oil").setup({
    default_file_explorer = true,
    use_default_keymaps = false,
    show_hidden = true,
    keymaps = {
        ["g?"] = "actions.show_help",
        ["<CR>"] = "actions.select",
        ["<BS>"] = "actions.parent",
        ["<leader>ss"] = "actions.select_vsplit",
        ["<leader>sh"] = "actions.select_split",

        ["<C-t>"] = "actions.select_tab",
        ["<A-p>"] = "actions.preview",
        ["<C-c>"] = "actions.close",
        ["<C-r>"] = "actions.refresh",
        ["-"] = "actions.parent",
        ["_"] = "actions.open_cwd",
        ["gs"] = "actions.change_sort",
        ["gx"] = "actions.open_external",
        ["g."] = "actions.toggle_hidden",
        ["`"] = "actions.toggle_hidden",
        ["g\\"] = "actions.toggle_trash",
    },
    vim.keymap.set("n", "<leader>e", "<CMD>Oil<CR>", { desc = "Open parent directory" }),
    vim.keymap.set('n', '<leader>gg', '<cmd>Fterm lazygit<cr>', { desc = 'Lazygit' })
})
