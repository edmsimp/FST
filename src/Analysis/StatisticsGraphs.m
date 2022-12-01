%% Importing Data
leven_stats = readtable('../../binaries/levenshtein_statistics.csv');
rb_stats = readtable('../../binaries/tree_statistics.csv');
fst_stats = readtable('../../binaries/fst_statistics.csv');

%% Dictionary Creation

prep_time = [leven_stats.executionTime_ns_(1), rb_stats.executionTime_ns_(1), fst_stats.executionTime_ns_(1)];
bar(prep_time / 10^6, 'FaceColor', '#D95319');
hold on;
title("Tempo de Preparação dos Métodos");
ylabel("Tempo (ms)");
xlabel("Método");
set(gca, 'xticklabel', {'Levenshtein', 'Árvore RB', 'FST'});
hold off;

print -dpng -r400 dict_creation.png

%% Studying the Used Dictionary
dictionary = readtable('/usr/share/dict/american-english').A;
letters = cellfun(@(s)lower(s(1)), dictionary);
[GC, GR] = groupcounts(letters);
bar(GC)
xticklabels({'a', 'e', 'j', 'o', 't', 'y'});
GR
print -dpng -r400 dict_dist.png

%% Single Character
% Levenshtein
leven_char = leven_stats.executionTime_ns_(2:27);

plot(leven_char(:, 1) / 10^6, 'LineWidth', 1.5, 'Color', '#0072BD');
hold on;
title("Caractere Único - Levenshtein");
ylabel("Tempo (ms)");
xlabel("Caractere");
xticks([1, 6, 12, 18, 26]);
xticklabels({'a', 'f', 'l', 'r', 'z'});
legend('Levenshtein');
hold off;
print -dpng -r400 leven_char.png

% RB Tree
rb_char = rb_stats.executionTime_ns_(2:27);

plot(rb_char(:, 1) / 10^3, 'LineWidth', 1.5, 'Color', '#D95319');
hold on;
title("Caractere Único - RB Tree");
ylabel("Tempo (us)");
xlabel("Caractere");
xticks([1, 6, 12, 18, 26]);
xticklabels({'a', 'f', 'l', 'r', 'z'});
legend('RB Tree');
hold off;
print -dpng -r400 rb_char.png

% FST

%% Set String
% Levenshtein
leven_str = leven_stats.executionTime_ns_(28:56);

plot(leven_str(:, 1) / 10^6, 'LineWidth', 1.5, 'Color', '#0072BD');
hold on;
title("String Selecionada");
ylabel("Tempo (ms)");
xlabel("Caractere");
legend('Levenshtein');
hold off;
print -dpng -r400 leven_str.png

% RB Tree
rb_str = rb_stats.executionTime_ns_(28:56);

plot(rb_str(:, 1) / 10^3, 'LineWidth', 1.5, 'Color', '#D95319');
hold on;
title("Char Único");
ylabel("Tempo (us)");
xlabel("Caractere");
legend('RB Tree');
hold off;
print -dpng -r400 rb_str.png

% FST


%% Random 100 Strings