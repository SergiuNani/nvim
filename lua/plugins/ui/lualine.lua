local lualine = require('lualine')
local icons = require('lib.icons')

local colors = {
    bg = '#202328',
    fg = '#bbc2cf',
    yellow = '#ECBE7B',
    cyan = '#008080',
    darkblue = '#081633',
    green = '#98be65',
    orange = '#FF8800',
    violet = '#a9a1e1',
    magenta = '#c678dd',
    blue = '#51afef',
    red = '#ec5f67',
}

local mode_color = {
    n = colors.green,
    i = colors.blue,
    v = colors.magenta,
    [''] = colors.magenta,
    V = colors.magenta,
    c = colors.yellow,
    t = colors.red,
    R = colors.orange,
    Rv = colors.orange,
    no = colors.fg,
    s = colors.violet,
    S = colors.violet,
    [''] = colors.violet,
    ic = colors.yellow,
    cv = colors.red,
    ce = colors.red,
    r = colors.cyan,
    rm = colors.cyan,
    ['r?'] = colors.cyan,
    ['!'] = colors.red,
}

local conditions = {
    buffer_not_empty = function()
        return vim.fn.empty(vim.fn.expand('%:t')) ~= 1
    end,
    buffer_is_file = function()
        return vim.bo.buftype == ''
    end,
    hide_in_width = function()
        return vim.fn.winwidth(0) > 80
    end,
    check_git_workspace = function()
        local filepath = vim.fn.expand('%:p:h')
        local gitdir = vim.fn.finddir('.git', filepath .. ';')
        return gitdir and #gitdir > 0 and #gitdir < #filepath
    end,
}
local progress = { 'progress', color = { fg = colors.fg, gui = 'bold' } }
local filetype = { 'filetype', color = { fg = colors.blue, gui = 'bold' } }
local filesize = { 'filesize', color = { fg = colors.fg, gui = 'bold' }, cond = conditions.buffer_not_empty }
local fileformat = { 'fileformat', icons_enabled = true, color = { fg = colors.white, gui = 'bold' } }

local filename = {
    'filename',
    cond = conditions.buffer_not_empty and conditions.buffer_is_file,
    color = { fg = colors.magenta, gui = 'bold' },
}

-- local buffers = { -- If you want tabs here they are
--     'buffers',
--     filetype_names = {
--         TelescopePrompt = icons.ui.Telescope .. 'Telescope',
--         lazy = icons.ui.Sleep .. 'Lazy',
--         mason = icons.ui.Package .. 'Mason',
--         NvimTree = icons.documents.OpenFolder .. 'Files',
--     },
--     use_mode_colors = true,
-- }

local branch = {
    'branch',
    icon = icons.git.Branch,
    fmt = function(str)
        return str:sub(1, 32)
    end,
    color = { fg = colors.green, gui = 'bold' },
}


local diagnostics = {
    'diagnostics',
    sources = { 'nvim_lsp', 'nvim_diagnostic', 'nvim_workspace_diagnostic' },
    symbols = {
        error = icons.diagnostics.Error,
        warn = icons.diagnostics.Warning,
        info = icons.diagnostics.Information,
        hint = icons.diagnostics.Hint,
    },
    diagnostics_color = {
        color_error = { fg = colors.red },
        color_warn = { fg = colors.yellow },
        color_info = { fg = colors.blue },
        color_hint = { fg = colors.yellow },
    },
}

local lsp = {
    function()
        local msg = 'No LSP'
        local buf_ft = vim.api.nvim_buf_get_option(0, 'filetype')
        local clients = vim.lsp.get_active_clients()
        if next(clients) == nil then
            return msg
        end
        for _, client in ipairs(clients) do
            local filetypes = client.config.filetypes
            if filetypes and vim.fn.index(filetypes, buf_ft) ~= -1 then
                return client.name
            end
        end
        return msg
    end,
    icon = icons.ui.Gear,
    color = { fg = colors.fg, gui = 'bold' },
}

local encoding = {
    'o:encoding',
    fmt = string.upper,
    cond = conditions.hide_in_width,
    color = { fg = colors.green, gui = 'bold' },
}

local separator = {
    function()
        return icons.ui.Separator
    end,
    color = function()
        return { fg = mode_color[vim.fn.mode()] }
    end,
    padding = { left = 0, right = 0 },
}

local function mode(icon)
    icon = icon or icons.ui.NeoVim
    return {
        function()
            return icon
        end,
        color = function()
            return { fg = mode_color[vim.fn.mode()] }
        end,
        padding = { left = 1, right = 0 },
    }
end

lualine.setup({
    options = {
        component_separators = '',
    },
    sections = {
        lualine_a = {
            {
                'tabs',
                tab_max_length = 40,            -- Maximum width of each tab. The content will be shorten dynamically (example: apple/orange -> a/orange)
                max_length = vim.o.columns / 3, -- Maximum width of tabs component.
                -- Note:
                -- It can also be a function that returns
                -- the value of `max_length` dynamically.
                mode = 2, -- 0: Shows tab_nr
                -- 1: Shows tab_name
                -- 2: Shows tab_nr + tab_name

                path = 0, -- 0: just shows the filename
                -- 1: shows the relative path and shorten $HOME to ~
                -- 2: shows the full path
                -- 3: shows the full path and shorten $HOME to ~

                -- Automatically updates active tab color to match color of other components (will be overidden if buffers_color is set)
                use_mode_colors = true,

                show_modified_status = true, -- Shows a symbol next to the tab name if the file has been modified.
                symbols = {
                    modified = '[+]',        -- Text to show when the file is modified.
                },

                fmt = function(name, context)
                    -- Show + if buffer is modified in tab
                    local buflist = vim.fn.tabpagebuflist(context.tabnr)
                    local winnr = vim.fn.tabpagewinnr(context.tabnr)
                    local bufnr = buflist[winnr]
                    local mod = vim.fn.getbufvar(bufnr, '&mod')

                    return name .. (mod == 1 and ' +' or '')
                end,
                color = {
                    -- Same values as the general color option can be used here.
                    active = colors.green,   -- Color for active tab.
                    inactive = colors.green, -- Color for inactive tab.
                },
            }
        },
        -- lualine_b = { "branch", 'location', progress, filename },
        lualine_b = { lsp, diagnostics, filetype },
        lualine_c = { 'location' },
        lualine_x = { branch, "diff", progress, },
        lualine_y = { filesize, fileformat, encoding, separator },
        lualine_z = {},
    },
})
