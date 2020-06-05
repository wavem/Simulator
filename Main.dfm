object FormMain: TFormMain
  Left = 0
  Top = 0
  Caption = 'Simulator'
  ClientHeight = 463
  ClientWidth = 780
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object ___pnBase: TPanel
    Left = 0
    Top = 126
    Width = 780
    Height = 337
    Align = alClient
    BevelOuter = bvNone
    Color = clWindowFrame
    ParentBackground = False
    TabOrder = 0
    ExplicitLeft = 200
    ExplicitTop = 176
    ExplicitWidth = 185
    ExplicitHeight = 41
  end
  object dxRibbon1: TdxRibbon
    Left = 0
    Top = 0
    Width = 780
    Height = 126
    Cursor = crHandPoint
    BarManager = BarMgr
    ColorSchemeName = 'Black'
    Contexts = <>
    TabOrder = 1
    TabStop = False
    object dxRibbon1Tab1: TdxRibbonTab
      Active = True
      Caption = 'dxRibbon1Tab1'
      Groups = <>
      Index = 0
    end
  end
  object BarMgr: TdxBarManager
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = #47569#51008' '#44256#46357
    Font.Style = []
    Categories.Strings = (
      'Default')
    Categories.ItemsVisibles = (
      2)
    Categories.Visibles = (
      True)
    PopupMenuLinks = <>
    UseSystemFont = True
    Left = 256
    DockControlHeights = (
      0
      0
      0
      0)
  end
end
