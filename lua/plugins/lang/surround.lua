require("nvim-surround").setup({

    keymaps = {
        -- insert = "<C-g>s",
        -- insert_line = "<C-g>S",

        normal = "s",
        normal_cur = "ss",
        normal_line = "yS",
        normal_cur_line = "ySS",

        visual = "s",
        -- visual_line = "gS",
        delete = "ds",
        change = "cs",
        -- change_line = "cS",
    },

})


-- sample* text                ssb            (sample text) ysst div<CR>
-- surr*ound_words             siw)           (surround_words)

-- *make strings               s$"            "make strings"
-- [delete ar*ound me!]        ds]             delete around me! (dsq, dsr)
-- remove <b>HTML t*ags</b>    dst             remove HTML tags
-- 'change quot*es'            cs'"            "change quotes"
-- <b>or tag* types</b>        csth1<CR>       <h1>or tag types</h1>
-- delete(functi*on calls)     dsf             function calls
