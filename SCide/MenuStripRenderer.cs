﻿using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ASM
{
    public class MenuStripRenderer : ToolStripProfessionalRenderer
    {
        public MenuStripRenderer() : base(new MenuStripColorTable()) { }

        public static void SetStyle(ToolStripItem item)
        {
            item.BackColor = Color.FromArgb(27, 27, 28);
            item.ForeColor = Color.FromArgb(241, 241, 241);
            item.Height = 22;
        }
    }

    //get { return Color.FromArgb(0, 122, 204); }
    public class MenuStripColorTable : ProfessionalColorTable
    {
        public override Color MenuItemSelected
        {
            get { return Color.FromArgb(51, 51, 52); }
        }
        public override Color ToolStripDropDownBackground
        {
            get { return Color.FromArgb(27, 27, 28); }
        }
        public override Color ToolStripBorder
        {
            get { return Color.FromArgb(27, 27, 28); }
        }
        public override Color ButtonSelectedBorder
        {
            get { return Color.Transparent; }
        }
        public override Color ButtonSelectedGradientBegin
        {
            get { return Color.FromArgb(62, 62, 64); }
        }
        public override Color MenuBorder
        {
            get { return Color.FromArgb(51, 51, 55); }
        }
        public override Color MenuItemBorder
        {
            get { return ButtonSelectedBorder; }
        }
        public override Color ButtonSelectedGradientEnd
        {
            get { return ButtonSelectedGradientBegin; }
        }
        public override Color ButtonPressedGradientBegin
        {
            get { return ToolStripDropDownBackground; }
        }
        public override Color ButtonPressedGradientEnd
        {
            get { return ButtonPressedGradientBegin; }
        }
        public override Color MenuItemPressedGradientBegin
        {
            get { return ToolStripDropDownBackground; }
        }
        public override Color MenuItemPressedGradientEnd
        {
            get { return ToolStripDropDownBackground; }
        }
    }
}
