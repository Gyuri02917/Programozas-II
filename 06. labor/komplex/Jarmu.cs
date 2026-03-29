using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace prog2
{
    internal class Jarmu
    {
        public int ENI { get; set; }
        public string Nev { get; set; }

        public int? Epult { get; set; }
        public bool? Aktiv { get; set; }
        public int? Motorok { get; set; }

        public double? TeljesitmenyKW { get; set; }
        public double? TeljesitmenyLE { get; set; }

        public double? Sebesseg { get; set; }
        public int? MaxUtas { get; set; }

        public Meretek Meret { get; set; }
        public int? LeszerelesEve { get; set; }

        public Tipus Tipus { get; set; }

        public Jarmu(int eni, string nev)
        {
            ENI = eni;
            Nev = nev;
            Meret = new Meretek();
        }

        public void SzamolTeljesitmeny()
        {
            if (TeljesitmenyKW == null && TeljesitmenyLE != null)
                TeljesitmenyKW = TeljesitmenyLE / 1.341;

            if (TeljesitmenyLE == null && TeljesitmenyKW != null)
                TeljesitmenyLE = TeljesitmenyKW * 1.341;
        }

        public virtual void Info()
        {
            Console.WriteLine($"{Nev} ({Tipus}) – ENI: {ENI}");
        }

        public override string ToString()
        {
            return
                $"Típus: {Tipus}\n" +
                $"ENI: {ENI}\n" +
                $"Név: {Nev}\n" +
                $"Épült: {Epult?.ToString() ?? "nincs adat"}\n" +
                $"Aktív: {(Aktiv == null ? "nincs adat" : (Aktiv.Value ? "igen" : "nem"))}\n" +
                $"Motorok száma: {Motorok?.ToString() ?? "nincs adat"}\n" +
                $"Teljesítmény: {TeljesitmenyKW?.ToString("0.00") ?? "?"} kW / " +
                $"{TeljesitmenyLE?.ToString("0.00") ?? "?"} LE\n" +
                $"Sebesség: {Sebesseg?.ToString() ?? "nincs adat"} km/h\n" +
                $"Max utas: {MaxUtas?.ToString() ?? "nincs adat"} fő\n" +
                $"Méretek:\n" +
                $"  - Legnagyobb hossz: {Meret.LegnagyobbHossz?.ToString() ?? "nincs adat"} m\n" +
                $"  - Hossz függély: {Meret.HosszFuggely?.ToString() ?? "nincs adat"} m\n" +
                $"  - Legnagyobb szélesség: {Meret.LegnagyobbSzelesseg?.ToString() ?? "nincs adat"} m\n" +
                $"  - Szélesség főbordán: {Meret.SzelessegFoborda?.ToString() ?? "nincs adat"} m\n" +
                $"  - Fixpont magasság: {Meret.FixpontMagassag?.ToString() ?? "nincs adat"} m\n" +
                $"  - Oldalmagasság: {Meret.Oldalmagassag?.ToString() ?? "nincs adat"} m\n" +
                $"  - Legnagyobb merülés: {Meret.LegnagyobbMerules?.ToString() ?? "nincs adat"} m\n" +
                $"Leszerelés éve: {LeszerelesEve?.ToString() ?? "nincs"}";
        }

    }
}
