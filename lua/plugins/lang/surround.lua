require("nvim-surround").setup({

    keymaps = {
        insert = "<C-g>s",
        insert_line = "<C-g>S",

        normal = "ss",
        normal_cur = "sss",
        normal_line = "sS",
        normal_cur_line = "sSS",

        visual = "S",
        visual_line = "gS",

        delete = "ds",
        change = "cs",
        change_line = "cS",
    },

})

-- surr*ound_words             ysiw)           (surround_words)
-- *make strings               ys$"            "make strings"
-- [delete ar*ound me!]        ds]             delete around me!
-- remove <b>HTML t*ags</b>    dst             remove HTML tags
-- 'change quot*es'            cs'"            "change quotes"
-- <b>or tag* types</b>        csth1<CR>       <h1>or tag types</h1>
-- delete(functi*on calls)     dsf             function calls
